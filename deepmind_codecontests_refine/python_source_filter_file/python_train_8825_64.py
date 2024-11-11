a,b=map(int,input().split())
for i in range(b*10,b*10+10):
    if i*0.08 == a:
        print(i)
        break
else:
    print(-1)