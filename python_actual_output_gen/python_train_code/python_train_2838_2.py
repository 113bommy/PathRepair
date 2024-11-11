L = [tuple(map(int, input().split())) for _ in range(int(input()))]
print('HPaopopry'[sorted(L, key=lambda x: x[0]) == sorted(L, key=lambda x: x[1])::2]+'Alex')