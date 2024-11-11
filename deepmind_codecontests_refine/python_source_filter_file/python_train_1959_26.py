from functools import*
d=lambda x,y:d(x,y%x)if y%x else x
_,a=open(0)
print(reduce(d,map(int,a.split())))