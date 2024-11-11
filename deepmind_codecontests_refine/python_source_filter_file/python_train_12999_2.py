n=int(input())
a=sorted(map(int,input().split()))[::-1]
j=i=x=0
while x<n:i+=a[i]>i;j+=a[j]>=i,x+=1
print('SFeicrosntd'[(a[i-1]^i|j^i)&1::2])
