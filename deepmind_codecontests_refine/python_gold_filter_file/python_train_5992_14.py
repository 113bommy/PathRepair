n=int(input())
l=list(map(int,input().split()))
S=sum(l)
p=S//(n//2)
for i in range(n) :
    for j in range(n) :
        if l[i]+l[j]==p and i!=j and l[i]!=-1 and l[j]!=-1 :
            print(i+1,j+1)
            l[i]=-1
            l[j]=-1
            break

        
