n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[0]*n
index=0
k=0
sum=0
for i in range(n):
    flag=True
    for j in range(k,n):
        flag=False
        if(c[b[i]-1]==1):
            print(0,end=" ")
            k+=1
            break
        if b[i]==a[j]:
            print(j+1-sum,end=" ")
            k=j
            sum+=(j+1-sum)
            break
        else:
            c[a[j]-1]=1
        
    if(flag):
        print(0,end=" ")
