n, c = map(int, input().split() )
a = list(map(int, input().split() ) )
r = 0
for i in range(1, n):
    r = r+1 if a[i] - a[i-1] <= c else 1
print(r)
