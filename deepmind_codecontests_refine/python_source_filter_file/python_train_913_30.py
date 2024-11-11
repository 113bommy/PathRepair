from functools import *
input()
print(reduce((lambda x,y:(x+y)/2), map(int,input().split())))