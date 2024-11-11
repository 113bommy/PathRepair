n,d=map(int,input().split())
a=list(map(int,input().split()))
cnt=0
a.sort()
for i in range(n):
    for j in range(i+1,n):
        if (a[j]-a[i])<=d:
            cnt+=1
        else:
            break
        
print(2*cnt)            