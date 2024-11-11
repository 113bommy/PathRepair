for i in range(int(input())):
    s = input().split()
    if int(s[1]) >= 2400 and int(s[2])>int(s[1]):
        print("YES")
        break
else:
    print("NO")
