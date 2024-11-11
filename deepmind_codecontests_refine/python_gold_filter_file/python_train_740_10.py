n=int(input())
l=list(map(int,input().split()))
d=dict()
for j in range(n*n):
    if l[j] not in d:
        d.update({l[j]:1})
    else:
        d[l[j]]+=1
four=0
t=0
f=0
#print(d)
for j in d:
    if d[j]%2==1:
        if n%2==1 and t==0: 
            t=1 
        else:
            f=1
            break
    if d[j]>=4:
        four+=d[j]//4
if f==1 or four<(n//2)**2:
    print("NO")
else:
    print("YES")
    a=[[0 for j in range(n)]for i in range(n)]
    for i in range(n//2):
        for j in range(n//2):
            for k in d:
                if d[k]>=4:
                    a[i][j]=k
                    a[n-1-i][j]=k
                    a[i][n-1-j]=k
                    a[n-1-i][n-1-j]=k
                    d[k]-=4
                    if d[k]==0:
                        del d[k]
                    break 
    #print(d)
    if n%2==1:
        for i in range(n//2):
            for k in d:
                if d[k]>=2:
                    #print(k)
                    a[i][n//2]=k
                    a[n-1-i][n//2]=k
                    d[k]-=2
                    if d[k]==0:
                        del d[k]
                    break 
        for i in range(n//2):
            for k in d:
                if d[k]>=2:
                    a[n//2][i]=k
                    a[n//2][n-1-i]=k
                    d[k]-=2
                    if d[k]==0:
                        del d[k]
                    break
        for k in d:
            if d[k]==1:
                a[n//2][n//2]=k
    for i in range(n):
        print(*a[i],sep=" ")
        
    
        
            