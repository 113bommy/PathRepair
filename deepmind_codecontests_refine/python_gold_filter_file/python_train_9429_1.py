n = int(input())
a = list(map(int,input().strip().split()))[:n]

a.sort()
flag = False
i = 0
while i < n-2 :
    if a[i] + a[i+1] > a[i+2] :
        flag = True
        break
    i += 1
if flag :
    print('YES')
else :
    print('NO')

# 1 2 3 4 5 