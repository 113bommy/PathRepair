n, l, r = input().split()
n, l, r = int(n), int(l), int(r)

# min
minlst = [1]
while len(minlst) < n:
    if l > n - len(minlst):
        for i in range(1, n-len(minlst)+1):
            minlst.append(2**i)
            break
    else:
        minlst.append(1)

# max
maxlst = [1]
while len(maxlst) < n:
    if r > len(maxlst):
        maxlst.append(2 ** len(maxlst))
    else:
        maxlst.append(maxlst[-1])

sum1 = sum(minlst)
sum2 = sum(maxlst)

print(f"{sum1} {sum2}")