m = int(input()) * 2
l = [input() for i in range(4)]

for i in range(1, 10):
    if sum([l[i].count(str(i)) for i in range(4)]) > m:
        exit(print('NO'))

print('YES')
