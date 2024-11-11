m=10**9+7
i=s=r=0
f=1
input()
a=input().split()
for x in a:i+=1;s+=pow(i,m-2,m);r+=int(x)*~-s+int(a[-i])*s;f=f*i%m
print(r*f%m)