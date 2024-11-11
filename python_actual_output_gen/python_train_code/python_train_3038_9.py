a, b = map(int,input().split())

for i in range(101):
    if i*8//100==a and i*10//100==b:
        print(i)
        exit()
print(-1)