# Hello World program in Python
n = int(input())
t = 2;
for i in range(1, n + 1):
    ans = (i * i * (i + 1) * (i + 1) - t) // i;
    t = i * (i + 1)
    print(ans)
