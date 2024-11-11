from sys import stdin, gettrace

if gettrace():
    def inputi():
        return input()
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def main():
    n,q = map(int, input().split())
    ss = list(map(lambda c: ord(c) - ord('a')+1, input()))
    counts = [[0]*27]
    for c in ss:
        counts.append(counts[-1].copy())
        counts[-1][c] += 1
    for _ in range(q):
        l,r = map(int, input().split())
        res = sum(c*(counts[r][c] - counts[l-1][c]) for c in range(1, 26))
        print(res)



if __name__ == "__main__":
    main()
