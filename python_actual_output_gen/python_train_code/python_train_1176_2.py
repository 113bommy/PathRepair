k = int(input())
t = 7
for i in range(1, k+1):
    if t == 0:
        print(i)
        break
    t = (t*10+7) % k
else:
    print(-1)