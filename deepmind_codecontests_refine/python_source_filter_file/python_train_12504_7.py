I=lambda:map(int,input().split())
n,k=I()
a=sorted(I())
l,q,w=[n],0,0
for i in range(1,n):
    n-=1
    if a[i]>a[i-1]:l+=[n]*(a[i]-a[i-1])
l.sort()
for i in range(len(l)):
    if q+l[i]==k:w+=1;q=0
    elif q+l[i]>k:w+=1;q=l[i]
    else:q+=l[i]
print(w+(q>0))