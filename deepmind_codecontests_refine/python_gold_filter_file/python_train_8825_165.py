a,b=map(int,input().split())
for i in range(1,100000):
    if i*8//100==a and i*1//10==b:
        print(i)
        exit()
print(-1)
