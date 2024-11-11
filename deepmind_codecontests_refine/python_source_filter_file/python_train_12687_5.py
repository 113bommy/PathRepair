import sys
a=[list(map(int,i.split(","))) for i in sys.stdin]
print(sum(map(lambda x:x[0]*x[1],a)))
print(round(sum(map(lambda x:x[1],a))/len(a)))
