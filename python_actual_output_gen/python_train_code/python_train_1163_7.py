a=int(input())
b=[int(s) for s in input().split()]
c=[int(s) for s in input().split()]
k=b+c
s=0
for i in range(1,a+1):
    if k.count(i)>0:
        s+=1
if s==a:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")