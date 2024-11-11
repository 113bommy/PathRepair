import sys
# from io import BytesIO
# from os import read, fstat
# input = BytesIO(read(0, fstat(0).st_size)).readline
# from os import path
#
# if path.exists("Input.txt"):
#     sys.stdin = open("Input.txt", "r")
#     sys.stdout = open("Output.txt", "w")
# input = lambda: sys.stdin.readline().rstrip()

input = sys.stdin.buffer.readline
# SOME SHIT
# map(int, input().split())
# sys.stdout.write("") ~ |



def solve_tc():
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    ans = float('-inf')
    for i in range(max(0, n - 110), n):
        for j in range(i + 1, n):
            ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]))
    return ans























t = int(input())
for _ in range(t):
    sys.stdout.write(str(solve_tc()) + "\n")