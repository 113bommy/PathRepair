n = int(input())
secuencia = [None] * n
ma = 0
for num, e in enumerate(input().strip().split()):
    en = int(e)
    secuencia[num] = [en, 0, num]
    ma = max(ma, en)
escritura = ["1"] * len(secuencia)
# ma = max((x[0] for x in secuencia))
bit = [0] * (ma + 1)

def max_x(x, l):
    suma = 0
    while x != 0:
        suma = max(suma, l[x])
        x -= (x & -x)
    return suma

def update_x(x, l, max_n, val):
    while x <= max_n:
        if val > l[x]:
            l[x] = val
        else:
            return
        x += (x & -x)

# def index_list(item, alist, first=0, last=-1):
#     pos = first
#     while first <= last:
#         midpoint = (first + last) // 2
#         pos = midpoint
#         if alist[midpoint][1] == item:
#             return midpoint
#         else:
#             if item > alist[midpoint][1]:
#                 last = midpoint - 1
#             else:
#                 first = midpoint + 1
#                 pos += 1
#     return pos

def new_get_secuence(e):
    num = secuencia[e][0]
    maximo = max_x(num - 1, bit) + 1
    update_x(num, bit, ma, maximo)
    return maximo

for e in range(n):
    secuencia[e][1] = new_get_secuence(e)

secuencia.sort(key=lambda x: (-x[1], -x[2]))
ultimos = [(ma + 1, 0, n)]
partir = 0
moment_max = secuencia[0][1]
# while moment_max > 0:
#     terminar = n
#     usados = []
#     for e in range(partir, n):
#         if secuencia[e][1] < moment_max:
#             terminar = e
#             break
#         for element in ultimos:
#             if secuencia[e][2] < element[2]:
#                 if secuencia[e][0] < element[0]:
#                     usados.append(secuencia[e])
#                     break
#     if len(usados) == 1:
#         escritura[usados[0][2]] = "3"
#     else:
#         for e in usados:
#             escritura[e[2]] = "2"
#     ultimos = usados
#     partir = terminar
#     moment_max -= 1
usados = []
for e in secuencia:
    if e[1] < moment_max:
        if len(usados) == 1:
            escritura[usados[0][2]] = "3"
        else:
            for y in usados:
                escritura[y[2]] = "2"
        ultimos = usados
        usados = []
        moment_max -= 1
    for element in ultimos:
        if e[2] < element[2]:
            if e[0] < element[0]:
                usados.append(e)
                break
        else:
            break
if len(usados) == 1:
    escritura[usados[0][2]] = "3"
else:
    for y in usados:
        escritura[y[2]] = "2"
print("".join(escritura))




