def arr_inp():
    return [int(x) for x in stdin.readline().split()]


from sys import stdin

n, a, ans = int(input()), sorted(arr_inp()), 0
for i in range(1, n):
    if a[i] <= a[i - 1]:
        ans += (a[i - 1] - a[i]) + 1
        a[i] += a[i - 1] - a[i] + 1

print(a)
