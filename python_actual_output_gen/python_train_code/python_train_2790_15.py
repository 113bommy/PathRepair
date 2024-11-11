n,k=[int(x) for x in input().split()]
rt=0
mas=sorted(set(([int(x) for x in input().split()])))
if mas[0]==0:
    mas.pop(0)
for item in mas:
    if k==0:
        break
    print(item-rt)
    rt+=item
    k-=1
for item in range(k):
    print(0)
    
