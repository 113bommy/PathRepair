t = int(input())
for _ in range(t):
    flag2 = 0
    n = int(input())
    s = input()
    if n == 11 and s[0] == '8':
        print("YES")
    elif n == 11 and s[0] != '8' or n < 11:
        print("NO")
    elif n > 11:
        a = n - 11
        for i in range(a):
            if s[i] == '8':
                flag2 = 1
                break
        if flag2:
            print("YES")
        else:
            print("NO")