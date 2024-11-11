n = int(input())
lis = list(map(int,input().split()))
c=0
ans=[]
k=n-1
for i in range(n-1,-1,-1):
    if lis[i]<i:
        ans.append([1,i+1,i-lis[i]])
        c+=(i-lis[i])
    else:
        req = (lis[i]+c)%n
        aa = n-req + i
        c+=n-req+i
        ans.append([1,i+1, aa])
ans.append([2,n,n])   
print(len(ans))          
for i in ans:
    print(*i)


    

