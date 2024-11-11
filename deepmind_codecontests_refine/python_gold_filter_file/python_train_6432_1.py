a = int(input())
b = list(map(int, input().split()))
p = round(sum(b) / a)

hp = 0
for i in b:
    hp += (i - p) ** 2

print(hp)
