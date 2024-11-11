n, k = [int(x) for x in input().split()]
z=0
lst = []
kol = 0
num= n//(k+1)
for i in range(1,n+1):
    if z==0:
        lst.append(i)
        z=k*2
        kol+=1
        continue
    
    z-=1

if lst[-1]+k>=n:
    print(kol)
    lst=[str(x) for x in lst]
    print(' '.join(lst))
elif lst[-1]+k<n:
    print(kol)
    lst = [x+(int(k)) for x in lst]
    lst = [str(x) for x in lst]
    print(" ".join(lst))
