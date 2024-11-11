n,t = list(map(int,input().split()))
s = list(input())
p = 0
index = n-1
for i in range(0,n):
	if s[i] == '.':
		p = i
	if p == 0 :
		continue
	if s[i] >= '5' :
		index = i
		break
while s[index] >= '5' and index > p and t>0 :
	if s[index-1] == '.' :
		index = index - 1
		break
	index = index - 1
	s[index] = str(int(s[index]) + 1)
	t = t - 1
flag = 0
# print(index,p)
if p == index :
	flag = 1
	index = index - 1
	while index >=0 and flag != 0 :
		if s[index] == '9' :
			s[index] = '0'
			flag = 1
		else :
			s[index] = str( int(s[index]) + 1)
			flag = 0
			index = index -1
	index = p - 1
if flag != 0 :
	print(1, end = "")
for i in range(0,index+1) :
	print(s[i],end = "")
print("")
