import math
import os
import random
import re
import sys


def solve(n, matrix):
    aisle = '|'
    buddy_seats = 'OO'
    result = 'NO'

    for row_index, row in enumerate(matrix):
        for col_index, col in enumerate(row):
            pair = col.split(aisle)
            for seat_index, seat in enumerate(pair):
                if seat == buddy_seats:
                    matrix[row_index][col_index] = matrix[row_index][col_index].replace(
                        "OO", "++"
                    )
                    result = 'YES'
                    return result

    return result


def print_seating_chart(matrix):
    """matrix is always 5 columns by `n` rows"""
    for row in matrix:
        for col in row:
            print(col)


if __name__ == '__main__':
    n = int(input())
    matrix = []

    for index in range(n):
        matrix.append(list(map(str, input().split())))

    result = solve(n, matrix)
    print(result)
    if result == 'YES':
        print_seating_chart(matrix)
