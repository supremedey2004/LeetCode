from threading import Semaphore

class Foo:
    def __init__(self):
        self.second_sem = Semaphore(0)
        self.third_sem = Semaphore(0)

    def first(self, printFirst):
        printFirst()
        self.second_sem.release()

    def second(self, printSecond):
        self.second_sem.acquire()
        printSecond()
        self.third_sem.release()

    def third(self, printThird):
        self.third_sem.acquire()
        printThird()