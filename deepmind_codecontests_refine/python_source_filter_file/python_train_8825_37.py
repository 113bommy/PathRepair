a, b = map(int,input().split())

for i in range(1001):
    if i*0.08==a and i*0.10==b :
        print(i)
        exit()
print(-1)