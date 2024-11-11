from sys import stdin


class base:
    def __init__(self, s, base):
        self.num, self.base = [0] + s, base

    def __add__(self, other):
        out = base([0] * (max(len(other.num), len(self.num)) - 1), self.base)
        carry = 0

        for i in range(len(self.num) - 1, -1, -1):
            su = self.num[i] + other.num[i] + carry
            if su < self.base:
                out.num[i], carry = su, 0
            else:
                out.num[i], carry = su % self.base, 1

        return out

    def __truediv__(self, other):
        carry = 0
        for i in range(1, len(self.num)):
            cur = self.num[i] + carry * self.base
            self.num[i], carry = divmod(cur, other)

        return self


letters = '0123456789ABCDEFGHIJKLMNOP'
rstr = lambda: [ord(x) - 97 for x in stdin.readline().strip()]

n, s1, t1 = int(input()), base(rstr(), 26), base(rstr(), 26)
s1 += t1
s1 =s1/ 2
print(''.join([chr(i + 97) for i in s1.num[1:]]))
