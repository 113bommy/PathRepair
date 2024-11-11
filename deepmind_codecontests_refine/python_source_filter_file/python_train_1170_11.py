# covers exactly 2 adjacent squares of the same row.

def solve():
    n,m,x,y=map(int,input().split())
    a=[input() for _ in range(n)]
    ans=0
    if y*2<x:
        for ai in a:
            *l,=ai.split("*")
            for li in l:
                ans+=y*(len(li)//2)
                ans+=x*(len(li)%2)
    else:
        for ai in a:
            *l,=ai.split("*")
            for li in l:
                ans+=len(li)*x
    print(ans)
        
t=int(input())
for _ in range(t):
    solve()

