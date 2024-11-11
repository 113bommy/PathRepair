n,k=map(int,input().split())
a=list(map(int,input().split()))
l=[]
c=0
r=0
c1=0
for i in range(1,n*k+1):
    if (i not in a):
        l.append(i)
        c+=1
    if (c>0 and c%(n-1)==0 and c>r):
        r1=c1*(n-1)
        r2=c
        print(a[c1],end=' ')
        print(*l[r1:r2],sep='')
        r=c
        c1+=1
    if(n==1):
        print(a[i-1])