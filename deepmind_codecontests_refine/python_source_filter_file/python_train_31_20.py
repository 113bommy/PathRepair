from math import ceil
has, going, perc = [int(x) for x in input().split()]
need = ceil(has * perc / 100)
print(need - going)