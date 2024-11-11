n,*a=map(int,open(0).read().split())
u=d=z=r=0
for i,j in zip(a[:n],a[n:]):
    if j-i>0:u+=(j-i)//2*2;r+=(j-i)%2
    elif j-i==0:z+=1
    else:d+=[j-i]
print("Yes" if u+2*d>=0 else "No")