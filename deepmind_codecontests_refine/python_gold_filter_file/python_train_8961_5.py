n=int(input())
p=list(map(int,input().split()))
a=[[0 for i in range(n)] for j in range(n)]
ans=[]
for i in range(n):
    bc=i
    while 1:
        a[i][bc]+=1
        if a[i][bc]==2:
            ans.append(bc+1)
            break
        bc=p[bc]-1
print(*ans)
        
            
    
