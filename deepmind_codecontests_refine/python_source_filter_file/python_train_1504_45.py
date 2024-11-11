# Problem Link: https://codeforces.com/problemset/problem/416/A
# Author: Raunak Sett
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

# do magic here

queries = int(input())

MAX_L = -1000000000
MAX_R = 1000000000

start = MAX_L
end = MAX_R

for i in range(queries):
    query = input()
    operator, n, res = query.split()
    number = int(n)
    result = False
    if res == "Y":
        result = True

    # Do stuff for positive results
    if result:
        if operator == ">":
            start = max(start, number+1)
        elif operator == ">=":
            start = max(start, number)
        elif operator == "<":
            end = min(end, number - 1)
        else:
            end = min(end, number)
    else:
        if operator == ">":
            end = min(end, number)
        elif operator == ">=":
            end = min(end, number - 1)
        elif operator == "<":
            start = max(start, number)
        else:
            start = max(start, number + 1)

possible = True
if start > end or end > MAX_L or start > MAX_R:
    possible = False

start = max(MAX_L, start)
end = min(MAX_R, end)

if not possible:
    print("Impossible")
else:
    print(start)