import math
T=int(input())
lst=[]
for i in range(T):
    n=int(input())
    for j in range(1,n+1):
        lst.append(math.pow(2,j))
    y=0
    b=0
    b+=lst[n-1]
    for x in range((n//2)-1):
        b+=lst[x]
    a=sum(lst)-b
    print(b-a)
    a=0
    b=0
    lst.clear()
    # print(lst)