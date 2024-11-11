# def checkKey(dict, key): 
# 	if key in dict:
# 		return True
# 	return False
# def helper(s):
# 	l=len(s)
# 	if (l==1):
# 		l=[]
# 		l.append(s)
# 		return l
# 	ch=s[0]
# 	recresult=helper(s[1:])
# 	myresult=[]
# 	myresult.append(ch)
# 	for st in recresult:
# 		myresult.append(st)
# 		ts=ch+st
# 		myresult.append(ts)

# 	return myresult


# mod=1000000000+7
# def helper(s,n,open,close,i):
# 	if(i==2*n):
# 		for i in s:
# 			print(i,end='')
# 		print()
# 		return
# 	if(open<n):
# 		s[i]='('
# 		helper(s,n,open+1,close,i+1)
# 	if(close<open):
# 		s[i]=')'
# 		helper(s,n,open,close+1,i+1)

# def helper(arr,i,n):
# 	if(i==n-1):
# 		recresult=[arr[i]]
# 		return recresult
# 	digit=arr[i]
# 	recresult=helper(arr,i+1,n)
# 	myresult=[]
# 	for i in recresult:
# 		myresult.append(i)
# 		myresult.append(i+digit);
# 	myresult.append(digit)
# 	return myresult
# import copy
# n=int(input())
# arr=list(map(int,input().split()))
# ans=[]
# def helper(arr,i,n):
# 	if(i==n-1):
# 		# for a in arr:
# 		# 	print(a,end=" ")
# 		# print()
# 		l=copy.deepcopy(arr)
# 		ans.append(l)
# 		return
# 	for j in range(i,n):
# 		if(i!=j):
# 			if(arr[i]==arr[j]):
# 				continue
# 			else:
# 				arr[i],arr[j]=arr[j],arr[i]
# 				helper(arr,i+1,n)
# 				arr[j],arr[i]=arr[i],arr[j]
# 		else:
# 			arr[i],arr[j]=arr[j],arr[i]
# 			helper(arr,i+1,n)
# def helper(sol,n,m):
# 	for i in range(n+1):
# 		for j in range(m+1):
# 			print(sol[i][j],end=" ")
# 		print()
# def rat_in_a_maze(maze,sol,i,j,n,m):
# 	if(i==n and j==m):
# 		sol[i][j]=1
# 		helper(sol,n,m)
# 		exit()
# 	if(i>n or j>m):
# 		return False
# 	if(maze[i][j]=='X'):
# 		return False
# 	maze[i][j]='X'
# 	sol[i][j]=1
# 	if(rat_in_a_maze(maze,sol,i,j+1,n,m)):
# 		return True	
# 	elif(rat_in_a_maze(maze,sol,i+1,j,n,m)):
# 		return True
# 	sol[i][j]=0
# 	return False
def helper(binum,digit):
	s=''
	count=0
	while(binum>0):
		if(binum&1==1):
			s='7'+s
			count+=1
		else:
			s='4'+s
		binum//=2
	if(count!=digit//2):
		return '-1'
	if(len(s)==digit):
		return s
	s='4'*(digit-len(s))+s
	return s
l=[]
for i in range(2,11,2):
	limit=2**i
	for j in range(limit):
		ans=helper(j,i)
		if(ans=='-1'):
			continue
		l.append(int(ans))
ll=0
ul=len(l)-1
n=int(input())
ans=0
while (ll<=ul):
	mid=(ll+ul)//2
	if(l[mid]>=n):
		ans=mid
		ul=mid-1;
	else:
		ll=mid+1
print(l[ans])








	























		




	

















