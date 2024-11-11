import sys
input = sys.stdin.readline
S = int(input())
print(0, 0, 10 ** 9, 1, -S % (10 ** 9), -(-S // (10 ** 9)))