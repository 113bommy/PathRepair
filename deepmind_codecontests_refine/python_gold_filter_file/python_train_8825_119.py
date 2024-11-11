x,y=map(int,input().split())

for i in range(10**6):
    if int(i*0.08)==x and int(i*0.1)==y:
        print(i)
        exit()
print(-1)