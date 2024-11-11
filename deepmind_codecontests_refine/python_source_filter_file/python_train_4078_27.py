# import sys

# sys.stdin = open("input.txt", "r")
# sys.stdin = open("output.txt", "w")

a, b = map(int, input().split())

print(((a ** 2) * b ** 2) % 998244353)