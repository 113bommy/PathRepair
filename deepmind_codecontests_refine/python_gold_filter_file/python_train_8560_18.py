t = int(input())
for i in range(t):
    x,m,n=map(int,input().split())
    if n*10>=x:
        print("YES")
        continue
    else:
        
        for i in range(m):
            x=x//2+10
      
        if(n *10 <x):
            print("NO")
        else:
            print("YES")
