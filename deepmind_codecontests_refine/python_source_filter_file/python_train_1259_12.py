for i in range(int(input())):
    n = int(input())
    s = input()

    for j in range(n // 2):
        if abs(ord(s[j]) - ord(s[n - j - 1])) in [0, 2]:
            print("NO")
            break
    else:
        print("YES")