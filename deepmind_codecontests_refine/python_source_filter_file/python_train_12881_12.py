n = int(input())
lst = [int(x) for x in input().strip().split()]
if 0 in lst:
    x = 1
else:
    x = 0
if len(set(lst)) == 1 and set(lst) != 0:
    print(1)
else:
    print(len(set(lst)) - x)