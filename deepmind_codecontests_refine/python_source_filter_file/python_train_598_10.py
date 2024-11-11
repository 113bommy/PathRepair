n,*a=open(0).read().split()
x=1000
for i in range(n-1):x+=x//a[i]*max(0,a[i+1]-a[i])    
print(x)