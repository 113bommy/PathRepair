n=int(input())
a=list(map(int, input().split()))
res,prev=0,0
for x in a:
    if x==prev or x==0:
        prev=0
        res+=1
    elif x==1 or x==2:
        prev=x
    elif prev>0 and x==3:
        prev=3-prev
print(res)
        