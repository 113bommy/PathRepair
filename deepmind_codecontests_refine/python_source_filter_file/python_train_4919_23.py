n,s = map(int,input().split())
 
if s<2*n:
    print("NO")
else:
    print("YES")
    for i in range(n-1):
        print(s//n,end=" ")
    print(s - (n-1)*(s//n))
        
    if s%n==1:
        print(2)
    else:
        print(1)
