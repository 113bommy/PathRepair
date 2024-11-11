import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 


_,a1,a2=rinput()
b1,_,b2=rinput()
c1,c2,_=rinput()

print((b2+c2)//2,a1,a2)
print(b1,(a2+c1)//2,b2)
print(c1,c2,(a1+b1)//2)