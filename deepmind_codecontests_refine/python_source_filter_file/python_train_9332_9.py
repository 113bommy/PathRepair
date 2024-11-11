n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
res=[[max(a1*b1 for b1 in b)]for a1 in a]
res.sort()
print(res[0][0])
