k = int(input())
a = 0
for i in range(k-1):
    a = (a*10+7)%k
    if a == 0:
        print(i+1)
        break
else:
    print(-1)