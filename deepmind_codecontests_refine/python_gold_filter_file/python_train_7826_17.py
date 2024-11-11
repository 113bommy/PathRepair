for _ in range(int(input())):
    x,y=map(int,input().split())
    if abs(x-y)==1:
        print("NO")
    else:
        print("YES")