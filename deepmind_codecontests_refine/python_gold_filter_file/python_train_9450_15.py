_,k,*a=map(int,open(0).read().split());a=[0]+a;p=1
while k:p=~-k%2*p or a[p];a=[a[b]for b in a];k//=2
print(p)