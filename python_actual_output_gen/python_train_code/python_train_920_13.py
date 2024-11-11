n = int(input())
s = input()[::2]
a = [0,0,0,0]
for i in range(n):
    a[int(s[i])-1] += 1
x = a[2] + a[3]
if a[2] > a[0]:
    x += int((a[1] + 1) / 2)
else:
    a[0] -= a[2]
    x += int((a[0] + 2 * a[1]) / 4)
print(x)
