t=int(input())
for _ in range(t):
    nm=input().split()
    n=int(nm[0])
    m=int(nm[1])
    
    arr=list(map(int,input().split()))
    
    if sum(arr)==m:
        print("YES")
    else:
        print("YES")