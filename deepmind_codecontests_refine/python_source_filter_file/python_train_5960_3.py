# from io import BytesIO
# import os
# input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


n, m, k = map(int, input().split())
ans = ''
if n != 1:
    ans += "U" * (n - 1)
if m != 1:
    ans += "L" * (m - 1)
for i in range(m):
    if i % 2:
        ans += "D" * (n - 1)
    else:
        ans += "U" * (n - 1)
    ans += "R"
print(len(ans))
print(ans)
    