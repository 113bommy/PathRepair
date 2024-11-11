soki = int(input())
dolya = list(map(int, input().split()))
sum = 0

for i in range(soki):
    print(dolya[i])
    sum += dolya[i]

print(sum / soki)