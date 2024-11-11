import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 


n,k,l,c,d,p,nl,np=rinput()
drink = k*l
toast=int(drink/n)
lime= c*d
salt= p/np
a=[toast,lime,salt]
m=min(a)
print(int(m/n))
