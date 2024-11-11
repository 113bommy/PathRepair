l, r = map(int, input().split())
print ('YES')
for i in range (l - 1, r , 2):
    print(l + i, l + i + 1)