n=int(input())
a=list(map(int,input().strip().split()))[:n]
q=int(input())
n=len(a)
dict1={}
eight=set()
six=set()
two=set()
four=set()
for i in a:
	if i in dict1:
		dict1[i]+=1
	else:
		dict1[i]=1
	if(dict1[i] >= 8 and i not in eight):
		if(i in six):
			six.remove(i)
		eight.add(i)
	elif(dict1[i] >= 6 and i not in six and i not in eight):
		if(i in four):
			four.remove(i)
		six.add(i)
	elif(dict1[i] >= 4 and i not in four and i not in six and i not in eight):
		if(i in two):
			two.remove(i)
		four.add(i)
	elif(dict1[i] >= 2 and i not in two and i not in four and i not in six and i not in eight):
		two.add(i)
while(q):
	s=input()
	sym=s[0:1];
	val=int(s[2:])
	if(sym=='+'):
		i=val
		if(i not in dict1):
			dict1[i]=1
		else:
			dict1[i]+=1
		n+=1
		if(dict1[i] >= 8 and i not in eight):
			if(i in six):
				six.remove(i)
			eight.add(i)
		elif(dict1[i] >= 6 and i not in six and i not in eight):
			if(i in four):
				four.remove(i)
			six.add(i)
		elif(dict1[i] >= 4 and i not in four and i not in six and i not in eight):
			if(i in two):
				two.remove(i)
			four.add(i)
		elif(dict1[i] >= 2 and i not in two and i not in four and i not in six and i not in eight):
			two.add(i)
	else:
		i=val
		dict1[i]-=1
		n-=1
		if(i in eight and dict1[i] < 8):
			eight.remove(i)
		if(i in six and dict1[i] < 6):
			six.remove(i)
		if(i in four and dict1[i] < 4):
			four.remove(i)
		if(i in two and dict1[i] < 2):
			two.remove(i)
		if(dict1[i] >= 8 and i not in eight):
			eight.add(i)
		if(dict1[i] >= 6 and i not in six and i not in eight):
			six.add(i)
		if(dict1[i] >= 4 and i not in four and i not in eight and i not in four):
			four.add(i)
		if(dict1[i] >= 2 and i not in two and i not in eight and i not in six and i not in four):
			two.add(i)
	if(n>=8):
		if(len(eight) >= 1):
			print("YES")
		elif(len(six)>=2 or len(four)>=2):
			print("YES");
		elif(len(six)==1 and (len(two)>=1 or len(four)>=1)):
			print("YES")
		elif(len(four)==1 and len(two)>=2):
			print("YES")
		else:
			print("NO")
	else:
		print("NO")
	q-=1