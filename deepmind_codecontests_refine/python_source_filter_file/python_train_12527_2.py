R = lambda: map(int, input().split())
s = input()
arr = []
for i, c in enumerate(s):
    if c == '.':
        arr.append(i)
n = len(s)
if not arr or not 1 <= arr[0] <= 8 or not 1 <= n - arr[-1] - 1 <= 3:
    print('NO')
elif not all(2 <= abs(y - x) <= 11 for x, y in zip(arr, arr[1:])):
    print('NO')
else:
    print('YES')
    st = 0
    for i in range(len(arr) - 1):
        en = arr[i] + (1 if arr[i + 1] - arr[i] - 1 < 4 else 3) + 1
        print(s[st: en])
        st = en
    if st < n:
        print(s[st:])