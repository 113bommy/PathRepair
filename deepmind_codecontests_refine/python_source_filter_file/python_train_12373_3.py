from itertools import groupby

s = [{c[0]: len(list(c[1])) for c in groupby(sorted(input()))} for _ in range(int(input()))]
out = ''.join([key * min([sx.get(key, 0) for sx in s]) for key in s[0]])

print(out)