def main():
    n = int(input())
    a = ord("a")
    orda = lambda x: ord(x)-a
    s = list(map(orda, list(input())))
    q = int(input())
    bits = [BIT(n) for _ in range(26)]
    for i, si in enumerate(s, 1):
        bits[si].add(i, 1)
    for _ in range(q):
        t, i, c = input().split()
        i = int(i)
        if t == "1":
            bits[s[i-1]].add(i, -1)
            bits[ord(c)-a].add(i, 1)
            s[i-1] = ord(c)-a
        else:
            c = int(c)
            cnt = 0
            for bit in bits:
                is_in = bit.sum_(c) - bit.sum_(i-1)
                if is_in:
                    cnt += 1
            print(cnt)
            
            
class BIT:
    __slots__ = ["length", "data"]
    def __init__(self, length):
        self.data = [0]*(length+1)
        self.length = length
    
    def add(self, i, x):
        while i < self.length+1:
            self.data[i] += x
            i += i&-i
    
    def sum_(self, i):
        x = 0
        while i > 0:
            x += self.data[i]
            i -= i&-i
        return x


if __name__ == "__main__":
    main()
