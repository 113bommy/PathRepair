T=int(input())
for t in range(T):
    n,d=map(int,input().split())
    print(n*(len(str(d+1))-1))
