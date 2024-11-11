from time import time
from random import randint
from functools import reduce
from sys import exit
a = time()
n, m = map(int, input().split())
matrix = []
for i in range(n):
    matrix.append([int(x) for x in input().split()])
while time() - a < 0.5:
    xor = []
    ind = []
    for i in range(n):
        x = randint(0, m - 1)
        xor.append(matrix[i][x])
        ind.append(x + 1)
    if reduce(lambda x, y: x ^ y, xor):
        print('TAK')
        print(*ind)
        exit()
print('NIE')

