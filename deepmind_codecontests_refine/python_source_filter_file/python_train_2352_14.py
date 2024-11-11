X = list(map(int, input().split()))
Houses = list(map(int, input().split()))
FHouse, LHouse = Houses[:X[1] - 1], Houses[X[1]:]
MINF, MINL = 1000, 1000
for i in range(FHouse.__len__() - 1, 0, -1):
    if FHouse[i] <= X[2] and FHouse[i] != 0:
        MINF = i
        break
for i in range(LHouse.__len__()):
    if LHouse[i] <= X[2] and LHouse[i] != 0:
        MINL = X[1] + i
        break
print(min(abs(MINL - X[1] + 1), abs(MINF - X[1] + 1)) * 10)
