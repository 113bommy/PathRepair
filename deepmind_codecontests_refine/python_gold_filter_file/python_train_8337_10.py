n, k = map(int, input().split())
t = input()
a = ''
for i in range(1, n):
    if str(t[:n - i]) == str(t[i:]):
        a = t[n - i:]
        break
if a == '':
    print(t * k)
else:
    print(t + a * (k - 1))