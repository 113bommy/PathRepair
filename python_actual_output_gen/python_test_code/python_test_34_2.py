import sys
n = int(sys.stdin.readline().rstrip("\n"))

if n < 5:
    res = n * (n-1) // 2
    print(n)
    exit(0)

sum = n + (n - 1)
l = len(str(sum))
if str(sum) == l * '9':
    print(1)
    exit(0)


res = 0
s = (l - 1) * '9'
for i in range(9):
    p = str(i) + s
    if int(p) <= n + 1:
        res += int(p) // 2
    elif int(p) > sum:
        break
    else:
        res += (1 + (sum - int(p)) // 2)
print(res)


