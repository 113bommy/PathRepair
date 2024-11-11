import collections as col

n, apples = int(input()), col.Counter(map(int,input().split(" ")))
if apples[200] == 1 and apples[100] == 0: print("NO")
elif apples[100] % 2 != 0: print("NO")
else: print("YES")