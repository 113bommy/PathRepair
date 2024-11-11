n=int(input())
a=list(map(int,input().split()))
ps=[]
sum=0
for i in range(0,n):
    sum+=a[i]
    ps.append(sum)
q=int(input())
while(q>0):
    l,r=map(int,input().split())
    sum=0
    if(l==1):
        sum=ps[r-1]
    else:
        sum=ps[r-1]-ps[l-1]
    print(int(sum/10))
    q-=1