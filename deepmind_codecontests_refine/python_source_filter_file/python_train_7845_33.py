for i in range(int(input())):
    a=int(input())
    s=0
    while s<360:
        s+=a
        if s==360:
            print("YES")
    if s>360:
        print("NO")