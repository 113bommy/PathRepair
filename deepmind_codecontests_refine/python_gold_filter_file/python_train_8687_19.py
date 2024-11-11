n, m, k = map(int, input().split())

armies = []

allies = 0

for _ in range(m+1):
    armies.append(int(input()))

player_army = armies[m]

for i in range(m):
    army = armies[i]
    different_forces = army ^ player_army
    number_of_different_forces = bin(different_forces).count('1', 2)
    if number_of_different_forces <= k:
        allies += 1

print(allies)
