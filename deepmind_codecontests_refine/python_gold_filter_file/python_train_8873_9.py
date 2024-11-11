import io
import os
import functools
import itertools
import math

#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
while t:
    t -= 1
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append([int(x) for x in input()])
    answer = True
    for i in range(n - 1):
        for j in range(n - 1):
            if matrix[i][j] == 1 and matrix[i + 1][j] != 1 and matrix[i][j + 1] != 1:
                answer = False
    print("YES" if answer else "NO")
