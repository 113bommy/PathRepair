n = int(input())
for a in range(0, n + 1, 1234567):
    for b in range(0, n + 1, 123456):
        if (n - a - b) % 1234 == 0:
            print("YES")
            exit(0)
print("NO")