input()
a = list(map(int, input().split()))
a.sort(reversed=True)
print(sum(a[::2]) - sum(a[1::2]))