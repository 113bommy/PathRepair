n, a, b = map(int, input().split())
cachet = [list(map(int, input().split())) for i in range(n)]
cachet.sort(key = lambda el: el[0] * el[1])
cachet.reverse()
maxim = 0
for i in range(n - 1):
    for j in range(i + 1, n):
        p1 = cachet[i]
        p2 = cachet[j]
        s = p1[0] * p1[1] + p2[0] * p2[1]
        if (p1[0] + p2[0] <= a and max(p1[1], p2[1]) <= b) or (p1[0] + p2[0] <= b and max(p1[1], p2[1]) <= a):
            if s > maxim:
                maxim = s
            break
        elif (p1[1] + p2[0] <= a and max(p1[0], p2[1]) <= b) or (p1[1] + p2[0] <= b and max(p1[0], p2[1]) <= a):
            if s > maxim:
                maxim = s
            break
        elif (p1[0] + p2[1] <= a and max(p1[1], p2[0]) <= b) or (p1[0] + p2[1] <= b and max(p1[1], p2[0]) <= a):
            if s > maxim:
                maxim = s
            break
        elif (p1[1] + p2[1] <= a and max(p1[0], p2[0]) <= b) or (p1[1] + p2[1] <= b and max(p1[0], p2[0]) <= a):
            if s > maxim:
                maxim = s
            break
print(maxim)
   
