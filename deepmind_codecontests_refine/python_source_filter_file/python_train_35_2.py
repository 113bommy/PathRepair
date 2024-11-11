import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 
mod = int(1e9)+7

s = input()
l = len(s)
d = {}

for i in range(l-9):
	# print(i)
	if s[i]!='-' and s[i+1]!='-' and s[i+2]=='-' and s[i+3]!='-' and s[i+4]!='-' and s[i+5]=='-' and s[i+6]!='-' and s[i+7]!='-' and s[i+8]!='-' and s[i+9]!='-':
		year = int(s[i+6:i+10])
		month = int(s[i+3:i+5])
		date = int(s[i:i+2])

		if (year<2013 or year>2015 or month<1 or month>12 or date<0):
			continue
		if ((month==1 and date>31) or (month==2 and date>28) or (month==3 and date>31) or (month==4 and date>30) or (month==5 and date>31) or (month==6 and date>30) or (month==7 and date>31) or (month==8 and date>31) or (month==9 and date>30) or (month==10 and date>31) or (month==11 and date>30) or (month==12 and date>31)):
			continue
		
		year = str(s[i+6:i+10])
		month = str(s[i+3:i+5])
		date = str(s[i:i+2])
		res = date + "-" + month + "-" + year
		d[res] = d.get(res, 0)+1

m = 0
ans = ''
for key in d:
	if d[key]>m:
		m = d[key]
		ans = key

print(ans)		