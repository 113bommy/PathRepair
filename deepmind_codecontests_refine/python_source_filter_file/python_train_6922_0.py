a,b=map(int,input().split())
n,m=map(int,input().split())
la=list(map(int,input().split()))
lb=list(map(int,input().split()))
la=la[:n+1]
lb=lb[b-m:]
print("YES" if min(lb)>max(la) else "NO")