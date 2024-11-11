cups = [int(i) for i in input().split()]
medals = [int(i) for i in input().split()]
n = int(input())
cup_sum = sum(cups)
medal_sum = sum(medals)

if cup_sum%5 == 0:
    ncup = cup_sum/5
else:
    ncup = cup_sum//5 + 1

if medal_sum%10 == 0:
    nmedal = medal_sum/10
else:
    nmedal = medal_sum//10 + 1

print(ncup)
print(nmedal)

if ncup+nmedal <= n:
    print('YES')
else:
    print('NO')
