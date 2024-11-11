from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans1 = sum(a[i] * i for i in range(n)) + sum(b[-i - 1] * (n + i) for i in range(n))
ans2 = a[0] + sum(b[i] * (i + 1) for i in range(n)) + sum(a[-i - 1] * (n + 1 + i) for i in range(n - 1))

N = 2 * n
right = [0] * n

if n == 1:
    print(b[0])
    exit()

if n % 2:
    s = a[-1] + b[-1]
    right[-1] = (N - 1) * b[-1] + (N - 2) * a[-1]

    for i in range(n - 3, -1, -2):
        c = (n - i) * 2
        right[i] = right[i + 2] - 2 * s + (N - 1) * b[i] + (N - 2) * b[i + 1] + (N - c + 1) * a[i + 1] + (N - c) * a[i]
        s += a[i] + a[i + 1] + b[i] + b[i + 1]

    s = a[-1] + b[-1] + a[-2] + b[-2]
    right[-2] = (N - 1) * a[-2] + (N - 2) * a[-1] + (N - 3) * b[-1] + (N - 4) * b[-2]

    for i in range(n - 4, -1, -2):
        c = (n - i) * 2
        right[i] = right[i + 2] - 2 * s + (N - 1) * a[i] + (N - 2) * a[i + 1] + (N - c + 1) * b[i + 1] + (N - c) * b[i]
        s += a[i] + a[i + 1] + b[i] + b[i + 1]

else:
    s = a[-1] + b[-1]
    right[-1] = (N - 1) * a[-1] + (N - 2) * b[-1]

    for i in range(n - 3, -1, -2):
        c = (n - i) * 2
        right[i] = right[i + 2] - 2 * s + (N - 1) * a[i] + (N - 2) * a[i + 1] + (N - c + 1) * b[i + 1] + (N - c) * b[i]
        s += a[i] + a[i + 1] + b[i] + b[i + 1]

    s = a[-1] + b[-1] + a[-2] + b[-2]
    right[-2] = (N - 1) * b[-2] + (N - 2) * b[-1] + (N - 3) * a[-1] + (N - 4) * a[-2]

    for i in range(n - 4, -1, -2):
        c = (n - i) * 2
        right[i] = right[i + 2] - 2 * s + (N - 1) * b[i] + (N - 2) * b[i + 1] + (N - c + 1) * a[i + 1] + (N - c) * a[i]
        s += a[i] + a[i + 1] + b[i] + b[i + 1]

temp = [(a[i] * (2 * i) + b[i] * (2 * i + 1), a[i] * (2 * i + 1) + b[i] * (2 * i))[i % 2] for i in range(n)]
left = [0] + list(accumulate(temp))
right += [0]

for_ans = [left[i] + right[i] for i in range(n + 1)]

print(max(for_ans))
