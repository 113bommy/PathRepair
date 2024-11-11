K = int(input())

p = 0
for i in range(100000000):
    p = (p*10+7) % K
    if p == 0:
        print(i+1)
        exit()
print(-1)

