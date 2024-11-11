n , x = [int(i) for i in list(input().split())]
factors = []
count = 0

for i in range(1,(x//2) + 1):
    if x%i == 0 :
        factors.append([i, int(x/i)])

for i in factors :
    if (i[0] >= 1 and i[0] <= n) and (i[1] >= 1 and i[1] <= n) :
        count += 1

print(count)