class Solution {
public:
    vector<pair<int, int>> rookDir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<pair<int, int>> bishopDir = {{1,1},{1,-1},{-1,1},{-1,-1}};
    vector<pair<int, int>> queenDir = {
        {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{1,-1},{-1,1},{-1,-1}
    };

    struct Move {
        int sx, sy;
        int dx, dy;
        int len;
    };

    int ans = 0;
    vector<Move> moves;

    bool inside(int x, int y) {
        return x >= 1 && x <= 8 && y >= 1 && y <= 8;
    }

    void simulate(int t, vector<pair<int,int>> &pos,
                  vector<int> &finished) {

        if (t == 8) {
            ans++;
            return;
        }

        vector<pair<int,int>> nxt = pos;
        vector<int> nf = finished;

        for (int i = 0; i < moves.size(); i++) {
            if (finished[i]) continue;

            if (t < moves[i].len) {
                nxt[i].first += moves[i].dx;
                nxt[i].second += moves[i].dy;
            } else {
                nf[i] = 1;
            }
        }

        // collision check
        for (int i = 0; i < nxt.size(); i++) {
            for (int j = i + 1; j < nxt.size(); j++) {
                if (nxt[i] == nxt[j]) return;
            }
        }

        simulate(t + 1, nxt, nf);
    }

    void dfs(int idx,
             vector<string>& pieces,
             vector<vector<int>>& positions) {

        if (idx == pieces.size()) {

            vector<pair<int,int>> start;
            vector<int> finished(moves.size(),0);

            for (auto &m : moves)
                start.push_back({m.sx,m.sy});

            simulate(0,start,finished);
            return;
        }

        vector<pair<int,int>> dirs;

        if (pieces[idx] == "rook")
            dirs = rookDir;
        else if (pieces[idx] == "bishop")
            dirs = bishopDir;
        else
            dirs = queenDir;

        int x = positions[idx][0];
        int y = positions[idx][1];

        // stay
        moves.push_back({x,y,0,0,0});
        dfs(idx+1,pieces,positions);
        moves.pop_back();

        // move in every direction
        for (auto &d : dirs) {
            int nx = x;
            int ny = y;
            int len = 0;

            while (true) {
                nx += d.first;
                ny += d.second;
                if (!inside(nx,ny)) break;

                len++;
                moves.push_back({x,y,d.first,d.second,len});
                dfs(idx+1,pieces,positions);
                moves.pop_back();
            }
        }
    }

    int countCombinations(vector<string>& pieces,
                          vector<vector<int>>& positions) {
        dfs(0,pieces,positions);
        return ans;
    }
};