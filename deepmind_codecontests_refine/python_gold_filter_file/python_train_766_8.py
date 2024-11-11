n = int(input())
a = list(map(int, input().split()))
arrayd = []
arraya = []
arrayk = []

for x in a:
    if x > 0:
        arrayd.append(x)
    elif x == 0:
        arrayk.append(x)
    else: arraya.append(x)
if len(arrayd) == 0:
    arrayd.append(arraya[-1])
    arrayd.append(arraya[-2])
    arraya = arraya[:len(arraya)-2]
if len(arraya) % 2 == 0:
    arrayk.append(arraya[-1])
    arraya = arraya[:len(arraya)-1]
print(len(arraya),end = " ")
for x in arraya:
    print(x, end = " ")
print()
print(len(arrayd),end = " ")
for x in arrayd:
    print(x, end = " ")
print()
print(len(arrayk),end = " ")
for x in arrayk:
    print(x, end = " ")
