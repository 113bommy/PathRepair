def check(listx,s):
	num = (listx[-2]+listx[1])%2
	if num!=listx[0] and s[0]=="o": return True
	elif num==listx[0] and s[0]=="x": return True
	else: return False
n = int(input())
s = input()
x,flag,ans = [[1,1],[1,0],[0,1],[1,0]],False,""
for i in range(4):
	for j in range(1,n):
		if (s[j]=="o" and x[i][-1]==1) or (s[j]=="x" and x[i][-1]==0): x[i].append(x[i][-2])
		else: x[i].append(1-x[i][-2])
	if x[i][0]==x[i][-1] and check(x[i],s):
		flag = True
		break
if flag:
	for k in x[i][:n]:
		if k==1: ans+="S"
		else: ans+="W"
	print(ans)
else: print(-1)