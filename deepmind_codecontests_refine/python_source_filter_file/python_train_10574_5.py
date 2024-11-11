s=input()
arr=[]
n=len(s)
flag1=flag2=flag3=flag4=0
count1=count2=count3=count4=0
for i in range(0,n,4):
	if s[i]!= '!' and flag1==0:
		arr.append(s[i])
		flag1=1
	elif s[i]=='!':
		count1+=1	
if flag1==0:
	arr.append('!')	
for i in range(1,n,4):
	if s[i]!= '!' and flag2==0:
		arr.append(s[i])
		flag2=1
	elif s[i]=='!':
		count2+=1	
if flag2==0:
	arr.append('!')	
for i in range(2,n,4):
	if s[i]!= '!' and flag3==0:
		arr.append(s[i])
		flag3=1
	elif s[i]=='!':
		count3+=1	
if flag3==0:
	arr.append('!')	
for i in range(3,n,4):
	if s[i]!= '!' and flag4==0:
		arr.append(s[i])
		flag4=1
	elif s[i]=='!':
		count4+=1	
if flag4==0:
	arr.append('!')	

dic={}
dic[arr[0]]=count1
dic[arr[1]]=count2
dic[arr[2]]=count3
dic[arr[3]]=count4
print(dic)
print(dic['R'],dic['B'],dic['Y'],dic['G'])











						

