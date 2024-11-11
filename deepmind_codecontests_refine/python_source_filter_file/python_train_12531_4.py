def f(a, b):
    global ans
    maks = max(a, b)
    mins = min(a, b)
    ans += (maks//mins)
#     print(ans)
    if (mins == 1):
        return ans
    else:
        if (maks % mins == 0):
            return ans + 1
        else:
            return f(maks%mins, mins)
for i in range(int(input())):
    a, b = list(map(int, input().split()))
    ans = 0
    print(f(a, b))