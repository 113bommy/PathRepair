# https://codeforces.com/problemset/problem/1167/A
for _ in range(int(input())):
    n = int(input())
    s = input()
    if n < 11:
        print("NO")
    elif n == 11:
        if s[0] == "8":
            print("YES")
        else:
            print("NO")
    else:
        for i in range(n - 10):
            if s[i] == "8":
                print("YES")
                break
        else:
            print("NO")