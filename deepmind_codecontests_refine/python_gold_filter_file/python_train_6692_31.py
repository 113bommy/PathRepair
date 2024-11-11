t = int(input())
for _ in range(t):
    x = input()
    res = ((int(x[0]) - 1) * 10) + (len(x) * (len(x) + 1)) // 2
    print(res)

