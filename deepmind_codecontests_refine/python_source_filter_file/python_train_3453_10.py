n=int(input())
l=list(map(int,input().split()))
from collections import Counter
c=Counter(l)
a=0
b=0
for i in c:
    if c[i]>=2:
        b=i
        a+=1
z=(n*(n-1))//2
if a>1:
    print('cslnb')
elif a==1:
    if c[b]>2:
        print('cslnb')
    else:
        if b-1 in l:
            print('cslnb')
        else:
            x=sum(l)-1
            if (x-z)%2:
                print('cslnb')
            else:
                print('sjfnb')
else:
    if (sum(l)-z)%2:
        print('sjfnb')
    else:
        print('cslnb')
    
