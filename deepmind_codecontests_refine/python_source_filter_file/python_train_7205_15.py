t = int(input())

for i in range(t):
    a, b, c, n = map(int, input().split())
    if (a+b+c+n)%3 == 0:
        tmp = (a+b+c+n)/3
        if a < tmp and b < tmp and c < tmp:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
