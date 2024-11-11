num_rooms = int(input())
dat = []

for _ in range(num_rooms):
    dat.append(tuple((map(lambda x: int(x), input().split()))))

valid = 0
for pair in dat:
    if pair[1] - pair[0] > 2:
        valid += 1
print(valid)
