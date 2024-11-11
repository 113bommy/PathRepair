"""
6 6 4
"""
import math

def solution(a):
    result = math.factorial(a)
    return result/((a**2)/2)


if __name__ == "__main__":
    a = int(input())
    result = solution(a)
    print(result)
