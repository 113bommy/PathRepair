import sys
input = sys.stdin.readline
m=int(input())
DC=[]
for i in range(m):
  DC.append(tuple(map(int,input().split())))
tot=0
for d,c in DC:
  tot+=c*(9+d)
print((tot-1)//9-1)
