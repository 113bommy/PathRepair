n = int(input())
a = input()
for i in range(n - 1):
    if a[i] > a[i + 1]:
        print(a[:i], a[i + 1], sep = '')
        break
else:
    print(a[1:])