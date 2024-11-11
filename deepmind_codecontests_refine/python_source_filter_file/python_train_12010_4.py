n = int( input().strip() )
arr = list( map(int, input().strip().split(' ')))
minv = 100
for i in arr:
    minv = min(i, minv)
for i in range(n):
    if arr[i] == minv:
        arr[i] = 100

minv = 100
for i in arr:
    minv = min(i, minv)
print( str(minv) if minv < 100 else 'NO' )