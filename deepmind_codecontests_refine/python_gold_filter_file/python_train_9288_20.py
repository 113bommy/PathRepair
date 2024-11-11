from math import ceil
for i in range(int(input())):
    n,d=map(int,input().split())
    if (n==1 and d==1):
        print("YES")
    elif n==1:
        print("NO")
    elif ceil(d/ceil((n/2)))+(ceil(n/2)-1)<=n:
        print("YES")
    else:
        print("NO")
        
        
        # 