import math
n = int(input())
if n < 25:
    print(-1)
    exit(0)
s = ['aeiou', 'eioua', 'iouae', 'ouaei', 'uaeio']
for i in range(5, int(math.sqrt(n)) + 1):
    if n % i == 0:
        tt = n // i
        for j in range(i):
            ans = s[j % 5] * (tt // 5)
            ans += s[j % 5][: tt % 5]
            print(ans, end='')
        exit(0)
