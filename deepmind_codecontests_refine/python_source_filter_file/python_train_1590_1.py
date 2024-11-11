def check(num, power):
    for i in range(3, 1000000000):
        if i ** power >= num:
            break

    return i        


num = int(input())
a = list(map(int, input().split()))
a.sort()
ans1 = a[0] - 1
ans2 = a[0] - 1
ans3 = a[0] - 1
val = check(a[-1], num - 1)

for i in range(1, num):
    ans1 += abs(a[i] - (val ** i))
    ans2 += abs(a[i] - 1)
    ans3 += abs(a[i] - ((val - 1) ** i))
print(min(ans1, ans2))    
