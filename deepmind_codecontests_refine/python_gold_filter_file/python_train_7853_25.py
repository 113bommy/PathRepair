import itertools
n = int(input())
arr = [int(i) for i in input().split()]
if len(set(arr)) == 1:
    print(0, int(n * ((n - 1) / 2)))
else:
    print(max(arr) - min(arr), int(arr.count(max(arr)) * arr.count(min(arr))))

