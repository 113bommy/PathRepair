r = [str(2**x) for x in range(50)]

def min_dif(str1, str2):
	c1=0
	c2=0
	for i in range(len(str1)):
		if(str1[i] == str2[c2]):
			c1+=1
			c2+=1
			if(c2==len(str2)):break
	return len(str1)-c1 + len(str2)-c1

for _ in range(int(input())):
	n = str(input())
	print(min(([min_dif(n,i) for i in r])))
