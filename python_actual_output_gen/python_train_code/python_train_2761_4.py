t = int(input())
for row in range(t):
    n = int(input())
    mas = [int(i) for i in input().split()]
    j = 0
    even_i = 0
    even_el = 0
    odd_i = 0
    odd_el = 0
    for i in range(len(mas)):
        if i%2 != mas[i]%2:
            if i%2: odd_i+=1
            else:even_i+=1
            if mas[i]%2: odd_el += 1
            else: even_el+=1
    if (even_i == odd_i): print(even_i-1)
    else: print(-1)