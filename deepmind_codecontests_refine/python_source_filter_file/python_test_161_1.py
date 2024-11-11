t=int(input())
for test in range(t):
    n=int(input())
    l=[]
    d={}
    for i in range(1,n+1):
        d[i]=1
    for i in range(n):
        l1=[]
        a,b=map(int,input().split())
        c=abs(a-b)
        l1.append(c)
        l1.append(a)
        l1.append(b)
        if a==b:
            l1.append(a)
            d[a]=0
        else:
            l1.append(0)
        l.append(l1)
    l.sort()
    for i in range(n):
        if l[i][3]==0:
            for j in range(l[i][2],l[i][1]+1):
                if d[j]==1:
                    l[i][3]=j
                    d[j]=0
                    break
    for i in range(n):
        print(l[i][1],l[i][2],l[i][3])
                
    
        
      
      
