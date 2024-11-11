n=int(input())
V=map(int,input().split())
v=list(V)

v=v.sort()
s=v[0]
for i in range(1,n):
    s=(s+v[i])/2

print(s)
