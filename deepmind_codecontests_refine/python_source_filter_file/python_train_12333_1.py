n,r,a=[int(x) for x in input().split()]
m=[[int(x) for x in input().split()] for _ in range(n)]
m.sort(key=lambda x:x[1])
s=n*a
l=sum(m[i][0] for i in range(n))
c=0
for j in range(n):
    if l+r-m[j][0]<s:
        c+=(r-m[j][0])*m[j][1]
        l+=r-m[j][0]
    else:
        c+=(s-l)*m[j][1]
        break
print(c)
