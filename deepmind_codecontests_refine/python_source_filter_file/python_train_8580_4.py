n, k = map(int, input().split())
arr = list(map(int, input().split()))
mx, idx = 0, 0
for i in range(1,1001):
    t = 0
    for j in range(n):
        t += (arr[j] == i + j * k)
    if t > mx:
        mx = t
        idx = i
res = str(n - mx) + '\n'
for j in range(n):
    if arr[j] > idx:
        res += '- ' + str(j+1) + ' ' + str(arr[j] - idx) + '\n'
    if arr[j] < idx:
        res += '+ ' + str(j+1) + ' ' + str(arr[j] + idx) + '\n'
    idx += k
print(res)
