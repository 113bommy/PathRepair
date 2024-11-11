for i in range(int(input())):
    a,b,c=map(int,input().split())
    if a//2==0 and b==c:
        print("YES")
    elif b//2==0 and a==c:
        print("YES")
    elif c//2==0 and a==b:
        print("YES")
    elif a==c+b and a-b==c:
        print("YES")
    elif b==a+c and b-a==c:
        print("YES")
    elif c==a+b and c-a==b:
        print("YES")
    else:
        print("NO")