n, a, b, c = list(map(int, input().split()))
 
res = 0
for x in range(c):
    for y in range(b):
        diff = n - 2*x - y
        if diff >= 0 and diff * 2 <= a:
            res+=1
print(res)