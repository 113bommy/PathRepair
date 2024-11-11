n = int(input())

b = []
for _b in list(map(int, input().split())):
    if _b > len(b) + 1:
        print('-1')
        exit()
    b.insert(_b, str(_b))

print('\n'.join(b))
