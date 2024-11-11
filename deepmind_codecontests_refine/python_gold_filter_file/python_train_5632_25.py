import collections as col

M = lambda: list(map(int,input().split()))
n, m = M()  #  number of the expedition participants and the number of the daily food packages available.
a = M()     #  type of food package

t=col.Counter(a).values()
w=0
for e in range(1,101):
    y=[]
    for a in t:
        y.append(a//e)
    if sum(y)>=n:
        w=e

print(w)