n=int(input())
l=list(map(int,input().split()))
l1=list(range(1,n+1))
i=0
L=0
R=0
c=0
while i<n:
    if l[i]!=l1[i]:
        if c==0:
            L=i
            c+=1
        else:
            R=i
            
    i+=1
if L!=0 and R!=0:
    if l[L:R+1]!=l1[L:R+1][::-1]:
        L=0
        R=0
        print(0,0)
    else:
        print(L+1,R+1)
else:
    print(0,0)
