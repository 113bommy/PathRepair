t = int(input(""))
tr = [0] * t

for x in range(0,t):
    nekaj = input("").split()
    a = int(nekaj[0])
    b = int(nekaj[1])
    pa = int(nekaj[2])+1
    pb = int(nekaj[3])+1

    rezultat = 0

    rezultat = (a-pa)*b
    if (rezultat < (b-pb)*a):
        rezultat = (b-pb)*a
    if (rezultat < (pb-1)*a):
        rezultat = (pb-1)*a
    if (rezultat < (pa-1)*b):
        rezultat = (pa-1)*a

    tr[x] = rezultat

for y in range(0,t):
    print(tr[y])
