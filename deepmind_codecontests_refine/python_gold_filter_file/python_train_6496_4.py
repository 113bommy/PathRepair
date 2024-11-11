
def splitarray(a):#a th array,splits into strictly increasing lists
	li=[]
	i=0
	while i<len(a):
		en=i
		p=[]
		p.append(a[i])
		for j in range(i+1,len(a)):
			if a[j]>=a[j-1]:
				en=j
				p.append(a[j])
			else:
				break
		i=en+1
		li.append(p)
# 	print(li)
	return li

s = input().split()
h = int(s[0])
a = input().split()
a = [int(item) for item in a]
ans=[]
i=0
ans = splitarray(a)
res = (len(ans)-1)*(h) + ans[-1][-1]-1
print(res)
