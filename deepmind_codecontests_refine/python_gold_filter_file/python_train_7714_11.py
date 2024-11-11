l, r = map(int, input().split())
print ('YES')
for i in range(0, r - l, 2):
    print(l + i, l + i + 1)
