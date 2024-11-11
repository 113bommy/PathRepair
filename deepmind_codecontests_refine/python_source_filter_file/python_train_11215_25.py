n = int(input())
packs = list(map(int, input().split()))
lowest_index = packs.index(min(packs))
if n == 1 or (n == 2 and packs[0] == packs[1]):
    print(-1)
else:
    print(1)
    print(lowest_index)
