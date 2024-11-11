import sys
large = 1000000
def solve():
    s = input()
    t = input()
    if len(s) != len(t):
        print(-1)
        return
    n = int(input())
    mem = [[large] * 26 for _ in range(26)]
    for i in range(26):
        mem[i][i] = 0
    for i in range(n):
        chra, chrb, strcost = input().split()
        a = ord(chra) - ord('a')
        b = ord(chrb) - ord('a')
        cost = int(strcost)
        mem[a][b] = min(mem[a][b], cost)
        for start in range(26):
            for end in range(26):
                mem[start][end] = min(mem[start][end], mem[start][a] + mem[a][b] + mem[b][end])
    cost = 0
    res = [None] * len(s)
    for i in range(len(s)):
        mid = -1
        midcost = large
        a = ord(s[i]) - ord('a')
        b = ord(t[i]) - ord('a')
        for j in range(26):
            if mem[a][j] != -1 and mem[b][j] != -1:
                thiscost = mem[a][j] + mem[b][j]
                if thiscost < midcost:
                    midcost = thiscost
                    mid = j
        res[i] = chr(ord('a') + mid)
        cost += midcost
    if cost >= large:
        print(-1)
        return
    print(cost)
    print(''.join(map(str, res)))


if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
solve()