t=int(input())
for _ in range(t):
    n,s,t=map(int,input().split())
    print(max(n-s,n-t)+1)
