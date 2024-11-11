n,m=map(int,input().split())
if m==0:
    print("YES")
    exit()
d=list(map(int,input().split()))
d.sort()
if d[0]==1 or d[-1]==n:
    print("NO")
    exit()
for i in range(len(d)-2):
    if d[i+1]!=d[i]+1:
        continue
    else:
    
        if d[i+2]==d[i+1]+1:
            print("NO")
            exit()
        
else:
    print("YES")
        
        