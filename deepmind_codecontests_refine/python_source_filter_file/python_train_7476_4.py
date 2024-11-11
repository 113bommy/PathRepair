m=10**9+7
input()
i=s=r=0
f=1
a=input().split()
for _ in a:
 s+=pow(i+1,m-2,m)
 r+=int(a[i])*~-s+int(a[~i])*s
 i+=1
 f*=i
print(r*f%m)