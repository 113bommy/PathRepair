from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf, log2, sqrt, log10
from bisect import bisect_right, bisect_left
from statistics import mode
from string import ascii_uppercase

cases = int(input())
matrix1 = []
for _ in range(cases):
    matrix1.append(list(input()))

matrix2 = []
for _ in range(cases):
    matrix2.append(list(input()))

def transpose(matrix):
    return [list(x) for x in zip(*matrix)]

def reverse_row(matrix):
    return matrix[::-1]

def reverse_column(matrix):
    return [x[::-1] for x in matrix]
def rotate_90(matrix):
    """this is counterclockwise, which is same as 270 clockwise"""
    return reverse_row(transpose(matrix))

def rotate_180(matrix):
    """same for both clockwise and counterclockwise"""
    return reverse_row(reverse_column(matrix))
def rotate_270(matrix):
    """this is counterclockwise, which is same as 90 clockwise"""
    return reverse_column(transpose(matrix))

if matrix1 == matrix2 or matrix1 == reverse_row(matrix2) or matrix1 == reverse_column(matrix2) \
    or matrix1 == rotate_90(matrix1) or matrix1 == rotate_180(matrix2) or matrix1 == rotate_270(matrix2):
    print("Yes")
    exit()

matrix2 = reverse_row(matrix2)
if matrix1 == matrix2 or matrix1 == reverse_row(matrix2) or matrix1 == reverse_column(matrix2) \
    or matrix1 == rotate_90(matrix1) or matrix1 == rotate_180(matrix2) or matrix1 == rotate_270(matrix2):
    print("Yes")
    exit()

matrix2 = reverse_column(matrix2)
if matrix1 == matrix2 or matrix1 == reverse_row(matrix2) or matrix1 == reverse_column(matrix2) \
    or matrix1 == rotate_90(matrix1) or matrix1 == rotate_180(matrix2) or matrix1 == rotate_270(matrix2):
    print("Yes")
    exit()
matrix2 = transpose(matrix2)
if matrix1 == matrix2 or matrix1 == reverse_row(matrix2) or matrix1 == reverse_column(matrix2) \
    or matrix1 == rotate_90(matrix1) or matrix1 == rotate_180(matrix2) or matrix1 == rotate_270(matrix2):
    print("Yes")
    exit()
else:
    print("No")

