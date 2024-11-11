t=int(input())

for i in range(t):
    l1,r1,l2,r2=[int(x) for x in input().split()]
    if(l1==l2):
       print(l1,r2)
    else:
        print(l1,l2)
 
