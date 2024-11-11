n, a = [int(i) for i in input().split()]
a -= 1
t = [int(i) for i in input().split()]
count = 0
for i in range(1, max(a, n - a)):
    if a + i < n and a - i >= 0:
        if t[a-i] == 1 and t[a+i] == 1:
            count += 2
    elif a + i < n and t[a+i] == 1:
        count += 1
    elif a - i >= 0 and t[a-i] == 1:
        count += 1
print(count + t[a])
