a = int(input())
m = [int(x) for x in input().split()]
summ = 1
maxx = 0
for i in range(1, a):
    if  m[i] >= m[i - 1]:
        summ += 1
        maxx = max(maxx, summ)
    else:
        summ = 1
        maxx = max(maxx, summ)
print(maxx)