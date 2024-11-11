n=int(input())
a=list(map(int,input().split(" ")))
s=0
i=count=0
while s<n:
    s+=a[(i)%7]
    i+=1
    count+=1
if count%7==0:
    print(7)
else:
    print(count%7)