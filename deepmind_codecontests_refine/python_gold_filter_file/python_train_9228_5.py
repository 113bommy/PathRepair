n = int(input())
a = list(map(int, input().split()))
diff = 0
failed = False
m = 0
for i in range(len(a) - 1):
    if abs(a[i] == a[i + 1]):
        failed = True
        break
    elif abs(a[i] - a[i + 1]) > 1:
        if diff == 0:
            diff = abs(a[i] - a[i + 1])
        elif abs(a[i] - a[i + 1]) != diff:
            failed = True
            break
    if a[i] > m:
        m = a[i]
if a[-1] > m:
    m = a[-1]

if failed:
    print("NO")
else:

    if diff == 0:
        print("YES")
        print(m, 1)
    else:
        for i in range(len(a) - 1):
            if abs(a[i] - a[i + 1]) == 1 and min(a[i], a[i + 1]) % diff == 0:
                failed = True

        if failed:
            print("NO")
        elif m % diff == 0:
            print("YES")
            print(m // diff, diff)
        else:
            print("YES")
            print(m // diff + 1, diff)
