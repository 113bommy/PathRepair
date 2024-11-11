for i in range(int(input())):
    a,b,c,m = map(int,input().split())
    maxi = a+b+c-3
    mini = max(a,b,c) - (a+b+c-max(a,b,c)-1)
    if m> maxi:
        print("NO")
    elif m< mini:
        print("NO")
    else:
        print("YES")