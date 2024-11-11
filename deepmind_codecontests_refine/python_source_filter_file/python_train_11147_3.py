n = int(input())
a = []
now = n
for i in range(2, n):
    while now % i == 0:
        now /= i
        a.append(i)
    if i * i > n:
        break
if now != 1:
    a.append(now)
print(str(n) + ":", end = "")
for i in a:
    print(" " + str(i), end = "")
print()
