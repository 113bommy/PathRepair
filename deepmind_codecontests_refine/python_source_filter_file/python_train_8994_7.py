import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 
mod = int(1e9)+7

n, m = rinput()
d = get_list()

if (1 in d or n in d):
	print("NO")
else:
	d.sort()
	flag = 0
	for i in range(m-3):
		if (d[i+2]==d[i+1]+1 and d[i+1]==d[i]+1):
			flag = 1
			break

	if flag == 0:
		print("YES")
	else:
		print("NO")	