n, m = map(int,input().split())
pairs = 0
for a in range(30):
    for b in range(30):
        if((a * a + b == n) and (a + b * b == m)):
            pairs += 1
print(pairs)