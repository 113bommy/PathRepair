n = int(input())
s = input()
t = input()
f=1
l1 = [0]*150
l2 = [0]*150
for i in range(n):
	l1[ord(s[i])]+=1
	l2[ord(t[i])]+=1

# dict d= {}
# for i in range(n):
# 	d[s[i]] = []
# for i in range(n):
# 	d[s[i]].append(i)

for i in range(150):
	if (l1[i]!=l2[i]):
		f=0
		break

if(f==0):
	print(-1)
else:
	k=0
	mov=[]
	done = [0]*n
	for i in range(n):
		c = t[i]
		ptr=-1
		for j in range(n):
			if(s[j]==c and done[j]==0):
				ptr = j
				break
		while(s[i]!=c):
			# print(c)
			if(k>10):
				break
			# print(s,t)
			# print("ptr",ptr,"i",i)
			if(ptr>i):
				mov.append(ptr)

				s1 = s[:ptr-1]+s[ptr]+s[ptr-1]+s[ptr+1:]
				# s1[ptr],s1[ptr-1]=s1[ptr-1],s1[ptr]
				ptr-=1;
				s =s1
			elif(ptr<i):
				mov.append(ptr+1)

				s1 =s [:ptr+1]+s[ptr+1]+s[ptr]+s[ptr+2:]
				ptr+=1;
				# s1[ptr],s1[ptr+1]=s1[ptr+1],s1[ptr]
				s = s1
			# print(s,t)
			k+=1
		done[ptr]=-1

	print(k)
	print (*mov)