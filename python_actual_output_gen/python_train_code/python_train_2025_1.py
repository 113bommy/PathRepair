t = int(input())
for _ in range(t):
    n = int(input())
    l =[]
    l1 = []
    for i in range(n):
        x,y=map(int,input().split())
        l.append(x)
        l1.append(y)
    l.sort()
    l1.sort()
    if n%2==1:
        print(1)
    else:
        a = l[n//2]-l[n//2-1]+1
        b = l1[n//2]-l1[n//2-1]+1
        print(a*b-1)
        
    
    
    