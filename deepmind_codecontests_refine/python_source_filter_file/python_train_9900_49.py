n,k=[int(i) for i in input().split()]
if k%2==0:
    z=k//2
else:
    z=k//2+1
if k-1>=n:
    mm=n
else:
    mm=k-1
#print(mm,z)
if n!=k:
    print(max(0,(mm-z+1)))
else:
    print(max(0,(mm-z)))
