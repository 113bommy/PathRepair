for _ in range(int(input())):
    l,r = list(map(int,input().split()))
    x = 2*l-1
    if x > r :
        print("YES")
    else :
        print("NO")