for i in range(int(input())):
    a,b,n,s=[int(x) for x in input().split()]
    if s%n<=b and s//n<=a+b//n:print("YES")
    else:print("NO")
