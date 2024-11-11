n = int(input())
arr = list(map(int, input().split()))
mx = 0
for i in range(n):
    c = 0
    co = 0
    for e in range(n):
        c+= arr[e]
        if c / (e+1) > 100 and e+1 > mx:
            mx = e+1
print(mx)