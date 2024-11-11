n = int(input())
factors = [str(n)]
for x in range(1, n // 2 + 1):
    if n % x == 0:
        factors.append(str(x))
f = False
for y in factors:
    if "1" in y or "2" in y or "3" in y or "5" in y or "6" in y or "8" in y or "9" in y or "0" in y:
        continue
    else:
        print("YES")
        f = True
        break
if not f:
    print("NO")

