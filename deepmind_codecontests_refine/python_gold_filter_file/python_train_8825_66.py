a,b=map(int,input().split())
for i in range(b*10,b*10+9):
    if int(i*0.08)==a:
        print(i)
        break
else:
    print(-1)