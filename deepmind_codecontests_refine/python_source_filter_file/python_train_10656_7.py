n=int(input())
sa=[]
sb=[]
for i in  range(n):
    a,b=map(int,input().split())
    sa.append(a)
    sb.append(b)
mi=100000000
ma=-1
f=0
for i in range(n):
    if sa[i]<mi:
        mi=sa[i]
    if sb[i]>ma:
        ma=sb[i]
for i in range(n):
    if sa[i]==mi and sb[i]==ma:
        f=1
        break
if f:
    print(i+1)
else:
    print(-1)

        