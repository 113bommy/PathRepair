p,n=map(int,input().split())
a=int(input())
c=max(p,n)
d=min(p,n)
lists=[[]for i in range(2*a)]
j=0
while j<2*a:
    lists[j],lists[j+1]=map(int,input().split())
    j=j+2
k=0
while k<2*a:
    if(lists[k]+lists[k+1]>=d and lists[k]+lists[k+1]<=2*d-c and lists[k]-lists[k+1]<=d and lists[k+1]-lists[k]<=d):
        print('YES')
    else:
        print('NO')
    k=k+2
