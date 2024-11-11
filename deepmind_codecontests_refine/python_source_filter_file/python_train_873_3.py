n, k = map(int, input().split())
count = 0
for i in range(n):
    ip = input()
    num = []
    for ch in ip:
        num.append(int(ch))
    for j in range(k):
        if j not in num:
            count += 1
            break
print(n-count)
