class Time:
    def __init__(self, h, m):
        self.h = h
        self.m = m

    def decr(self, x):
        for _ in range(x):
            if self.m > 0:
                self.m -= 1
            elif self.h > 0:
                self.h -= 1
                self.m = 59
            else:
                self.h = 11
                self.m = 59

    def is_lucky(self):
        return self.h % 10 == 7 or self.m % 10 == 7


x = int(input())
h, m = map(int, input().split())
t = Time(h, m)
out = 0

while not t.is_lucky():
    t.decr(x)
    out += 1

print(out)
