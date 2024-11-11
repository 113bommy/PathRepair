n,m=(int(i) for i in input().split())
a=[j for i in range(n) for j in list(str(input()))]
s=0
for i in a:
    if i=='B':
        s+=1
t=0
for i in range(m*n):
    if a[i]=='B':
        t+=1
    if t==(s+1)//2:
        print((i//n)+1,i%m+1)
        break
