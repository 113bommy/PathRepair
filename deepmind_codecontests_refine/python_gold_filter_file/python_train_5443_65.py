for _ in range(int(input())):
    a,b = map(int,input().split())
    if b>=2*a:
        print("NO")
    else:
        print("YES")