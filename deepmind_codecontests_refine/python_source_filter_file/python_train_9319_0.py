n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
sa = a[0]
sb = b[0]
for i in range(1, n):
    sa |= a[i]
    sb |= b[i]
    print(sa, sb)
print(sa+sb)
