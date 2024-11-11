n=int(input())
d=map(int,input().split())
v=list(d)

v.sort()
print(v)
s=v[0]
for i in range(1,n):
    s=(s+v[i])/2

print(s)
