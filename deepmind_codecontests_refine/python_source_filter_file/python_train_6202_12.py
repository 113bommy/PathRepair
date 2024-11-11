M = lambda: map(int, input().split())
s, x1, x2 = M()
t1, t2 = M()
p, d = M()
v1, v2 = 1/t1, 1/t2
if p <= x1 <= x2 and d > 0:
    path_by_tram =  x2 - p
elif p <= x2 <= x1 and d > 0:
    path_by_tram = s - p + s - x2
elif x1 <= p <= x2 and d > 0:
    path_by_tram = 2 * s + x2 - p
elif x1 <= x2 <= p and d > 0:
    path_by_tram = 2 * (s - p) + p - x2
elif x2 <= x1 <= p and d > 0:
    path_by_tram = 2 * (s - p) + p - x2
elif x2 <= p <= x1 and d > 0:
    path_by_tram = 2 * (s - p) + p - x2
elif p <= x1 <= x2 and d < 0:
    path_by_tram = 2 * p + x2 - p
elif p <= x2 <= x1 and d < 0:
    path_by_tram = 2 * s
elif x1 <= p <= x2 and d< 0:
    path_by_tram = 2 * p + x2 - p
elif x1 <= x2 <= p and d < 0:
    path_by_tram = p + x2
elif x2 <= x1 <= p and d < 0:
    path_by_tram = p - x2
elif x2 <= p <= x1 and d< 0:
    path_by_tram = 2 * s + p - x2


on_foot = abs(x2 - x1) / v2
print(int(min(round(path_by_tram/v1), on_foot)))
