n=int(input())
a=list(map(int,input().rstrip().split()))
sol=0
for i in range(1,min(10001,a[0])):
    if i>a[0]:
        break
    b=[0]*n
    b[0]=True
    for j in range(1,n):
        if a[j]>=i and (b[j-1]==True or b[j-2]==True):
            b[j]=True
        if j+1<n:
            if b[j]==True and a[j+1]>=i:
                b[j+1]=True
        if j+2<n:
            if  b[j]==True and a[j+2]>=i:
                b[j+1]=True
    #print(b)
    if b[n-1]==True:
        sol=max(i,sol)
print(sol)
            