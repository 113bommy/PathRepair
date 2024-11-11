import sys

numbers = [int(i) for i in sys.stdin.readline().split()]

m = numbers[0]
n = numbers[1]

print(int(m*n) / 2)