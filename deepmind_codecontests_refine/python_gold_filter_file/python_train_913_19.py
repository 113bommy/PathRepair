from functools import *
input()
print(reduce((lambda x,y:(x+y)/2), sorted(map(int,input().split()))))