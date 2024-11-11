a = [2, 6, 2, 3, 3, 3, 2, 5, 1, 2]
l = int(input())
r = int(l % 10)
l = int(l / 10)
print(a[l] * a[r])