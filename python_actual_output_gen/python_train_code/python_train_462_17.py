
a, b, c = map(int, input().split(' '))
if b > a and c > 0:
    if (b-a) % c == 0:
        print("YES")
    else:
        print("NO")
elif b <= a and c < 0:
    if (a-b) % -c == 0:
        print("YES")
    else:
        print("NO")
elif b is a:
    print("YES")
else:
    print("NO")
