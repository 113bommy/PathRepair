a,b,c=[int(i) for i in input().split()]
if c == 0:
    if a == b:
        print("YES")
    else:
        print("NO")
else:
    if (b-a) % c == 0 and b*c>0:
        print("YES")
    else:
        print("NO")
