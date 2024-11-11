m=10**9+7
i=s=r=f=1
input()
a=input().split()
for x in a:r+=int(x)*~-s+int(a[-i])*s;f=f*i%m;i+=1;s+=pow(i,m-2,m)
print(r*f%m-1)