from collections import Counter
input()
c = Counter([min(int(i)//400,8) for i in input().split()])
lt3200 = [bool(c[i]) for i in range(8)].count(True)
print(max(1, lt3200), lt3200+d[8])