import bisect;n,k=map(int,input().split());s=input();f=[0]*n;f[0]=1-int(s[0])
for i in range(1,n):f[i]=(1-int(s[i]))*int(s[i-1])
for i in range(n-1):f[i+1]+=f[i];a=0
for l in range(n):r=bisect.bisect_right(f,k+f[l]*int(s[l]));a=max(a,r-l)
print(a)