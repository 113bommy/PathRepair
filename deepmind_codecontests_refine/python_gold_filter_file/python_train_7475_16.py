I=lambda:map(int,input().split());n,q=I();s=input();a=[0]
for i in range(n):a+=[a[i]+(s[i-1:i+1]=='AC')]
while q:l,r=I();print(a[r]-a[l]);q-=1