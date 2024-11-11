t = int(input())

for i in range(t):
    b = input()
    ans = b[:2]
    for i in range(3, len(b), 2):
        ans = ans + b[i]
    print(ans)
