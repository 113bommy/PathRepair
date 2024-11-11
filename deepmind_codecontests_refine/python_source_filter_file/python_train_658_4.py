
a=int(input())
l1=list(map(int,input().split()))
b=int(input())
l2=list(map(int,input().split()))
c=0
m=-1
for i in range(a):
    for j in range(b-1,-1,-1):
        if(l2[j]%l1[i]==0):
            x=l2[j]//l1[i]
            print(l2[j],l1[i],x)
            if(x>m):
                m=x
                c=1
            elif(x==m):
                c+=1
            print(c)
            break
                
                
print(c)