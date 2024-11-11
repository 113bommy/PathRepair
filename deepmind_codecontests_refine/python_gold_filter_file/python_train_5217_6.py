import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 


n=iinput()
s=n-10
if(s==2 or s==3 or s==4 or s==5 or s==6 or s==7 or s==8 or s==9 or s==1 or s==11):
    print(4)
elif(s==10):
    print(15)
else:
    print(0)
    