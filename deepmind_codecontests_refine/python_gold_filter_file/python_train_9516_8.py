v = int(input())
a = list(map(int, input().split()))

c =[0 for i in range(10)]
globMin = float('inf')
globMinIndex = -1
for i in range(9):
    if a[i] <= globMin:
        globMin = a[i]
        globMinIndex = i

c[globMinIndex + 1] = v//globMin
ans = v//globMin
v = v % globMin
# print(globMinIndex)
for i in range(9, globMinIndex + 1, -1):
    if v <= 0:
        break
    j = i - 1
    c[i] += v // (a[i - 1] - globMin)
    c[globMinIndex + 1] -= v // (a[i - 1] - globMin)
    v = v % (a[i - 1] - globMin)

r = ''
for i in range(9, 0, -1):
    r += str(i) * c[i]

if ans == 0:
    print(-1)
else:
    # print(ans)
    print(r)