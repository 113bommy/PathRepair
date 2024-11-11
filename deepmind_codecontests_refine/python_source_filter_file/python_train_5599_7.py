import sys
sys.setrecursionlimit(10**8)
def main():
    n, a, b, c, d = map(int, input().split())
    memo = {}
    def dfs(x):
        if x == 0:
            return 0
        elif x == 1:
            return d
        elif x in memo:
            return memo[x]
        else:
            ret = min(
                d * x,
                d * (x - x//2*2) + a + dfs(x//2),
                d * ((x+1)//2*2-x) + a + dfs((x+1)//2),
                d * (x - x//3*2) + b + dfs(x//3),
                d * ((x+2)//3*3 - x) + b + dfs((x+2)//3),
                d * (x - x//5*5) + c + dfs(x//5),
                d * ((x+4)//5*5 - x) + c + dfs((x+4)//5)
            )
            memo[x] = ret
            return ret
    print(dfs(n))

t = int(input())
for i in range(t):
    main()