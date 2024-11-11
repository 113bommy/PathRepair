n=int(input())
l=0
r=n
for i in range(n):
    x=i*(i+1)//2
    if(r<x):
        break
    else:
        l=l+1
        r=r-x
print(l)