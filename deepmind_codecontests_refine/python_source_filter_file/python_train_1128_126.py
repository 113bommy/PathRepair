import math
n=input()
a= [min(math.floor(int(i)//400),8) for i in input().split()]
a7= len(set([i for i in a if i<=7]))
a8= len([i for i in a if i==8])
print(a7,a7+a8)