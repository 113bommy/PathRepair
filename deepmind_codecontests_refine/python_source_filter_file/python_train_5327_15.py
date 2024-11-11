t=int(input())
for _ in range(t):
    n,s,t=map(int,input().split()) 
    print(min(n,s+1,t+1))