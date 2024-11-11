n = int(input())
a = input()
b = input()
count = 0
for i in range(n//2):
    if a[i] == b[i]:
        if a[n-i-1] != b[n-i-1]:
            count += 1
    elif a[i] == b[n-i-1]:
        if a[n-i-1] != b[i]:
            count += 1
    elif a[i] == a[n-i-1]:
        if b[i] != b[n-i-1]:
            count += 2
    elif a[n-i-1] == b[n-i-1]:
        count += 1
    elif a[n-i-1] == b[i]:
        count += 1
    elif a[i] != b[i] and a[i] != b[n-i-1] and a[i] != a[n-i-1] and b[i] != a[n-i-1] and b[i] != b[n-i-1] and a[n-i-1] != b[n-i-1]:
        count += 2
    else:
        count += 2
if n % 2 != 0:
    if a[(n//2)] != b[(n//2)]:
        count += 1
print(count)