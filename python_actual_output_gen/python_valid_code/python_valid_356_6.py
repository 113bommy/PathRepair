t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    for j in range(2, k + 1):
        n += int(max(str(n))) * int(min(str(n)))
        if min(str(n)) == '0':
            break
print(n)