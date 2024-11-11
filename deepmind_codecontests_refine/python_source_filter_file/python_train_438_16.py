t=int(input())
def solve():
    n=int(input())
    a=list(map(int,input().split()))
    x=[h%n for h in a]
    d=[0]*n*2
    for i in range(0,2*n):
        d[i]=x[i%n]+i
    print(d)
    if(len(set(d))==len(d)):print("YES")
    else: print("NO")

for test in range(t):
    solve()