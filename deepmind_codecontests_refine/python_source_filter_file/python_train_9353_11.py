from collections import deque

n, l, t = map(int, input().split())
ants = [list(map(int, input().split())) for i in range(n)]

ants_t = [0]*n
count = 0
for i in range(n):
    ant = ants[i]
    if ant[1] == 1:
        c, ant_t = divmod(t + ant[0], l)
    else:
        c, ant_t = divmod(-t + ant[0], l)
    ants_t.append(ant_t)
    count += c
# print(ants_t, count)
ants_d = deque(sorted(ants_t))
# print(ants_d)

ants_d.rotate(-count)
# print(ants_d)
for ant in ants_d:
    print( (ant) % l )
