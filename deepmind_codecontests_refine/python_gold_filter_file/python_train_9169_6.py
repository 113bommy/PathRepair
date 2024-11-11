COINS = int(input())

ARRAY = list()

SPLIT = input().split(' ')

for i in range(COINS):
    ARRAY.append(int(SPLIT[i]))

COUNT = '1'


ARRAY.sort()
highest_val = 0
for i in range(len(ARRAY)):
    num = ARRAY.count(ARRAY[i])
    if highest_val < num:
        highest_val = num
        COUNT = str(num)

print(COUNT)