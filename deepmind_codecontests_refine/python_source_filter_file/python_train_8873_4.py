t=int(input())
for _ in range(t):
    n=int(input())
    l=[]
    for i in range(n):
        p=[]
        z=input()
        for j in z:
            p.append(int(j))
        l.append(p)    
            
        
    c=0    
    for i in range(n):
        for j in range(n):
            if l[i][j]==1 and j==n-1 :
                continue 
            elif j+1<n and l[i][j]==1 and l[i][j+1]==1:
                continue
            elif i+1<n and l[i][j]==1 and l[i+1][j]==1:
                continue
            elif l[i][j]==0:
                continue
            elif l[i][j]==1 and j==n-1:
                continue
            else:
                c+=1 
                break 
        if c==1:
            break 
    if c==0:
        print('YES')
    else:
        print('NO')