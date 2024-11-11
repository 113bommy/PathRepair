k,t = map(int,input().split())
a= list(map(int,input().split()))
sa = sum(a)
ma = max(a)

print(max(sa-ma-1,0))