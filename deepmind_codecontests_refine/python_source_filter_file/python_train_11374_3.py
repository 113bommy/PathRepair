n=int(input())
for _ in range(n):
    r,c=map(int,input().split())
    grid=[]
    d={}
    for i in range(r):
        l=list(map(int,input().split()))
        grid.append(l)
    for i in range(r):
        for j in range(c):
            s=i+j
            s1=r-i-1+c-j-1
            if(s!=s1 and s1 not in d):
                t=grid[i][j]
                t1=grid[r-i-1][c-j-1]
                if(s not in d):
                    d[s]=[0,0]
                d[s][t]+=1
                d[s][t1]+=1
    c=0
    print(d)
    for i in d:
        c+=min(d[i])
    print(c)
            
    
