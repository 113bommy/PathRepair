n = int(input())
m = input().split()
m.insert(0,'0')
c = 0

for i in range(0,len(m)-1):
	if  int(m[i+1]) <= int(m[i]) + 15 :
		c = int(m[i+1]) + 15
	else :
	 break

if (c > 90): c = 90

print(c)