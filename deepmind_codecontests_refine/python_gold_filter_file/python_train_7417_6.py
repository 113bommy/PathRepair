t = int(input())
for _ in range(t):
    s = input()
    print(s[0] + s[1:-1:2] + s[-1])