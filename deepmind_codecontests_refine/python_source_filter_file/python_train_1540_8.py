n,m＝ map(int,input().split())
L=list(map(int,input().split()))
print(n-sum(L) if n-sum(L)>=0 else -1)