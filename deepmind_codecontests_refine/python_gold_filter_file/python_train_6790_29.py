t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    print(n*(len(str(m+1))-1))