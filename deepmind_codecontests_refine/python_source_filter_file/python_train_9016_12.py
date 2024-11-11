import sys
n,k,m=map(int,input().split())
a=list(map(int,input().split()))
c=[0 for i in range(m)]
l=0
for i in a:
    c[i%m]+=1
for i in range(len(c)):
    if c[i]>=k:
        l=i
        break
else:
    print('NO')
    sys.exit()
print('YES')
f=''
for i in a:
    if i%m==l:
        f+=str(i)+' '
        k-=1
        if k==0:break
print(f)

