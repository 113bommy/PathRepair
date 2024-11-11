n,m = map(int, input().split())
#max of a,b is 32
pairs = 0
for a in range(33):
    for b in range(33):
        if(True):
            if(a ** 2 + b == n and a + b ** 2 == m):
                pairs += 1
print(pairs)
