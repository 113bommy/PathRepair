k = int(input())
a = 7
for i in range(1, 10**7):
    if a == 0:
        print(i)
        exit()
    a = (a*10+7)%k
print(-1)