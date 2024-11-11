n, k = map(int, input().split())
count = n
count1 = 0
last1 = []
if n % (2 * k + 1) < k + 1 and n % (2 * k + 1) != 0:
    last = k + 1 - (k + 1 - (n % (2 * k + 1)))
    last1.append(last)
    count1 += 1
    count -= k + last
    while count > 0:
        last += 2 * k + 1
        last1.append(last)
        count1 += 1
        count -= 2 * k + 1
else:
    last = k + 1
    last1.append(last)
    count1 += 1
    while count > 2 * k + 1:
        last += 2 * k + 1
        last1.append(last)
        count1 += 1
        count -= 2 * k + 1
print(count1)
print(" ".join(map(str, last1)))