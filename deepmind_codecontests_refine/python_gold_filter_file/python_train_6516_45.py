import sys
def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def minput():   return map(int, input().split()) 
def listinput(): return list(map(int, input().split()))
n=iinput()
s='aabb'
print(s*(n//4)+s[:n-(n//4)*4])