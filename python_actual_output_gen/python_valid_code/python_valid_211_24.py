i=lambda:map(int,input().split())
n,l=i()
a=sorted(i())
print(max(r-1 for l,r in zip([-a[0]]+a,a+[2*1-a[-1]]))/2)