import sys
h,m,s,a,b = map(int,input().split())
if h == 12:
    h = 0
# clockwise
b1 = 6*s
b2 = 6*m + s/10
b3 = h*30 + m/2 + s/120
a = 30*a
b = 30*b
arr = [(b1, 0), (b2, 0), (b3, 0), (a, 1), (b, 1)]
arr.sort()
if arr[0][1] == 1 and arr[-1][1] == 1:
    print('YES')
    sys.exit()
# print(arr)
for i in range(4):
    if arr[i][1] == 1 and arr[i+1][1]==1:

        print('YES')
        sys.exit()
print('NO')
