import math
 
import sys
#def get_ints(): 
#  return map(int, sys.stdin.readline().strip().split())
def inpu():
  return sys.stdin.readline().strip()
 
#T = int(input())
 
lets = 'abcdefghijklmnopqrstuvwxyz'
key = {lets[i]:i for i in range(26)}


#for t in range(T):
#n = int(input())
n,m = map(int,input().split())
#s = list(map(int,input().split()))
#t = list(map(int,input().split()))  
s = input()
t = input()
#b = inpu()
#a = input()
d = False


mins = [-1]*m
j = 0
for i in range(n):
  if s[i] == t[j]:
    mins[j] = i
    j+=1
  if j>=m:
    break

maxs = [-1]*m
j = m-1
for i in range(n-1,-1,-1):
  if s[i] == t[j]:
    maxs[j] = i
    j-=1
  if j< 0:
    break

ans = 0
for i in range(1,m):
  ans = max(maxs[i]-mins[i-1],ans)

print(ans)