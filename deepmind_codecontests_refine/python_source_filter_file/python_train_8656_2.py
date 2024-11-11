t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if '8' in s:
        i = s.index('8')
        if i == 0 and n == 1:
            print("YES")
        else:
            d = n - i
            if d < 11:
                print("NO")
            else:
                print("YES")
    else:
        print("NO")
