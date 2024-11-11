
from collections import Counter
n=int(input())
for i in range(n):
    a=input()
    b=Counter(a)
    x=0
    y=0
    for i in b:
        if b[i]>=2:
            x+=1
        else:
            y+=1
    print(x+y//2)