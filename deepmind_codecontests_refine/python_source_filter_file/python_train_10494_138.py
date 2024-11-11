n, a, b, c, d = map(int, input().split())
s = input()

if "##" in s[a-1:c] or "##" in s[b-1:d]:
    print("No")
elif c < d:
    print("Yes")
elif "..." in s[b-2:d]:
    print("Yes")
else:
    print("No")