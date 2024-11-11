p,r=input,range
A=sum([list(map(int,p().split()))for _ in r(3)],[])
b=[int(p())for _ in r(int(p()))]
print('YNeos'[any([sum(1<<i for i in r(9)if A[i]in b)&v==v for v in[7,56,73,84,146,273,292,448]])::2])