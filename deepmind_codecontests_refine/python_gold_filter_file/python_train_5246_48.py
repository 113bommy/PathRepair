n = int(input())
road = input()
s, t = -1, -1
r = road.count("R")
l = road.count("L")
lista = list() * n
if l == 0 or r == 0:
    #print(r, l)
    for i in range(1, n - 1):
        if road[i] == "R" or road[i] == "L":
            lista.append(i + 1)
    if r != 0:
        print(min(lista), max(lista)+1)
    else:
        print(max(lista), min(lista)-1)
else:
    for i in range(1, n):
        if road[i] == "R" and road[i + 1] == "L":
            s = i + 1
            if s > 0 or i == n - 1:
                break

    for i in range(2,n):
        if road[-i - 1] == "R" and road[- i] == "L":
            t = n - i + 1
            if t > 0:
                break
    print(s, t)