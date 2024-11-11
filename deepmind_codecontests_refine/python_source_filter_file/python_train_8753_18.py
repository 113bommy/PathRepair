n, k, s = map(int, input().split())

if (n - 1) * k < s or s < k:
    print('NO')
    exit()


def check(p):
    return s - p * (n - 1) - (k - p - 1) < n - 1


def binSearch(a, b):
    left, right = a - 1, b + 1

    while right - left > 1:
        mid = (left + right) // 2

        if check(mid):
            right = mid

        else:
            left = mid

    return right


b = binSearch(1, k)

print('YES')

temp_ = k - b - 1
temp = s - b * (n - 1) - temp_ + 1

ans = [n, 1] * (b // 2) + [n] * (b % 2)

if temp_ >= 0:
    if b % 2 == 0:
        ans.append(temp)
        ans += [temp - 1, temp] * (temp_ // 2) + [temp - 1] * (temp_ % 2)

    else:
        ans.append(n - temp + 1)
        ans += [n - temp + 2, n - temp + 1] * (temp_ // 2) + [n - temp + 2] * (temp_ % 2)

print(' '.join(map(str, ans)))
