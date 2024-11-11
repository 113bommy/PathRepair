n = int(input())
a, b = [int(x) for x in input().split()]
c1, d1 = [int(x) for x in input().split()]
c2, d2 = [int(x) for x in input().split()]
i = 0
j = 0
k = 0
if a<=n and b<=n and c1<=n and d1 <=n and c2 <=n and d2<=n:
    if (b-d1)/(a-c1)==1 or (b-d1)/(a-c1)==-1 or (b-d2)/(a-c2)==1 or (b-d2)/(a-c2)==-1 :
        k =1
    else :
        k=0
    if d1 >d2:
        y2=d1
        y1=d2
    if d2>=d1:
        y2=d2
        y1=d1
    if c1 >=c2:
        x2=c1
        x1=c2
    if c2>c1:
        x2=c2
        x1=c1
    if b<=y2 and b>=y1 :
        i =1
    else :
        i=0
    if a<=x2 and a>=x1:
        j = 1
    else :
        j = 0
    if i == 1 or j ==1 or k==1:
        print("NO")
    else :
        print("YES")
else :
    print("false")
    
        