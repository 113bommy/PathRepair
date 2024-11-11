for a0 in range(int(input())):
    n=int(input())
    s=list(input())
    if n>=11:
        if "8" in s:
            if n-s.index("8")<11:
               print("NO")
            else:
               print("YES")
        else:
            print("NO")
    else:
        print("NO")