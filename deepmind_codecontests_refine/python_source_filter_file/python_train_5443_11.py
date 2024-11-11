for _ in range(int(input())):
    l,r = list(map(int,input().split()))
    if l*2-1 >= r/2+1:
        print("YES")
    else:
        print("NO")