class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        cleaned = ""

        # Keep only alphanumeric characters and convert to lowercase
        for ch in s:
            if ch.isalnum():
                cleaned += ch.lower()

        # Check palindrome
        return cleaned == cleaned[::-1]