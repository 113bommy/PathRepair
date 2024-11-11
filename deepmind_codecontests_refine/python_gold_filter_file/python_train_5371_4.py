import fractions


def pretest(data):
    res = data[0]
    for x in data[1:]:
        res = fractions.gcd(res, x)
        if res == 1:
            return False
    return True


l = int(input())
a = list(map(int, input().split()))

cnt = 0
odd = l % 2 == 1


if pretest(a):
    print("YES")
    print(0)
    exit()


for i in range(0, l-1):
    if a[i] % 2 != 0:
        if a[i+1] % 2 != 0:
            cnt += 1
            a[i+1] = 2
        else:
            cnt += 2
            a[i+1] = 2

if a[-1] % 2 != 0:
    cnt += 2

print("YES")
print(cnt)