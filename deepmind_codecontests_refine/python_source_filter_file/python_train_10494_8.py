n, a, b, c, d = map(int, input().split())
s = input()

if c == d or "##" in s[a:d-1]:
    print("No")
elif c < d:
    print("Yes")
else:
    if "..." in s[b-2:d] and "##" not in s[a:c-1]:
        print("Yes")
    else:
        print("No")