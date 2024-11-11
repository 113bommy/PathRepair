input()
a = list(map(int,input().split()))
a.sort()
b,c = [[i for i in a if i > 500000],[i for i in a if i <= 500000]]
try:
    mymax = max(c) - 1
except:
    mymax = 0
try:
    yourmax = 1000000 - min(b)
except:
    yourmax = 0
print(max(mymax,yourmax))
