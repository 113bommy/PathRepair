n, d = map(int, input().split())
l = list(map(int, input().split(' ')))
sum = 0

for i in range(len(l)):
    sum += l[i]


if sum+(n-1)*10 >= d:
    print(-1)
else:
    print((d-sum)//5)

