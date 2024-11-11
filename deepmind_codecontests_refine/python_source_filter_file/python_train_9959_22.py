a=list(map(int,input().split()))
l=list(map(int,input().split()))
m=a[1]
n=0
su=0
c=0
for i in range(a[0]):
    if l[i]>=0:
        su=su+l[i]
        if su>=0:
            ma=a[1]-su
            if ma<m:
                m=ma
    else :
        su=su+l[i]
        if su<0:
            mi=abs(su)
            if mi>n:
                n=mi
if n<=a[1]:
    print(m-n+1)
else:
    print(0)
                
    