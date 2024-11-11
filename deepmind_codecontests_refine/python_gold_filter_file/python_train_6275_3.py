rn = lambda: int(input())
rns = lambda: map(int, input().split())
rl = lambda: list(map(int, input().split()))
rs = lambda: input()
yn = lambda x: print('Yes') if x else print('No')

for _ in range(rn()):
    n=rn()
    def solve(n):
        if n==1:
            return 0
        from math import ceil
        a=ceil(n**0.5)
        ans=(a-1)+ceil(n/a)-1
        return ans
    print(solve(n))




