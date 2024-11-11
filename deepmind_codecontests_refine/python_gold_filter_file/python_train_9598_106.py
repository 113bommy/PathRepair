n,a,b = map(int,input().split())

if a + b < n:
    print(b+1)
else:
    print(min(n-a,b))

    
