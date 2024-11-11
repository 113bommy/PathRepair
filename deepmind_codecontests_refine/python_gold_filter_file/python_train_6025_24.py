n, l = map(int, input().split())
a = list(map(int, input().split()))

flag = -1
for i in range(n - 1):
    if l <= a[i] + a[i + 1]:
        flag = i + 1
if flag == -1:
    print("Impossible")
    exit()

print("Possible")
for i in range(1, flag):
    print(i)
for i in range(flag + 1, n)[::-1]:
    print(i)
print(flag)
      