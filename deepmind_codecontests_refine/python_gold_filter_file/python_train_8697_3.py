n, v = int(input()), 0
for i in map(int, input().split()):
    #v = 0
    v ^= i - 1
    print(1 if v & 1 else 2)