import math
t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    maxx=0
    for j in range(1,n):
        if(l[j]>=l[j-1]):
            continue
        else:
            diff=l[j-1]-l[j]
            curr=int(math.log(diff+1,2))+1
            l[j]=l[j-1]
            if(curr>maxx):
                maxx=curr
    print(maxx)
    