n=list(map(int,input().split()))
a=(n[1]*n[2])/n[6]
b=n[3]*n[4]
p=n[5]/n[7]
x=min(a,b,p)
y=x/n[0]
print(int(y))
