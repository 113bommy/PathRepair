n, a, b, c, d = map(int, input().split())
s = input()

if c == d or "##" in s[:d-1]:
    print("No")
elif c < d:
    print("Yes")
else:
    if "..." in s[:d] and "##" not in s[:c-1]:
        print("Yes")
    else:
        print("No")
