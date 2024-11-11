a,b = map(int,input().split())
for i in range(1,200):
    if i*8//100==a and i*10//100==b:
        print(i)
        break
else:
    print(-1)