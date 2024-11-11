import bisect
input()
given = [int(x) for x in input().split()]
for i in [int(x) for x in input().split()]:
    print(bisect.bisect(given, i), end=" ")
