n,k=[int(x) for x in input().split()]
ai=[int(x) for x in input().split()]
cnt=0
c=0
line=0
for i in range(1,n*k+1):
    if(c==0 and line!=n):
        print(ai[cnt],end=" ")
        c+=1
        line+=1
    if(i not in ai and c!=n):
        print(i,end=" ")
        c+=1
    if(c==n):
        c=0
        cnt+=1
        print() 