for i in range(int(input())):
    l,r=list(map(int,input().split()))
    if l>2*r:
        print("YES")
    else:
        print("NO")