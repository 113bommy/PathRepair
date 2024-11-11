for _ in range(int(input())):
    n,k=map(int,input().split())
    if n%(k+1)>=(k+1)/2:
        print("YES")
    else:
        print("NO")