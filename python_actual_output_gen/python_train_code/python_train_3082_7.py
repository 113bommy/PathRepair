n=int(input())
a=[]
a.append(0)
a+=list(map(int,input().split()))
print(a)
for i in range(1,n+1):
    b=[0]*(n+1)
    j=i
    #b[j]+=1
    while(True):
        b[j]+=1
        if(b[j]==2):
            print(j)
            break
        j=a[j]
        
        
    