s=input()
pre=[]
suff=[]
j=0
for i in range(len(s)-1):

	if s[i]==s[i+1] and s[i]!="o":
		j+=1
	elif s[i]=='o':
		# print(s[i])
		pre.append(j)
if s[len(s)-1]=='o':
	pre.append(j)
j=0
for i in range(len(s)-1,0,-1):
	if s[i]==s[i-1] and s[i]!="o":
		j+=1
	elif s[i]=='o':

		suff.append(j)
if s[0]=='0':
	suff.append(j)
suff.reverse()
ans=0
print(pre)
print(suff)
for i in range(len(pre)):
	ans+=pre[i]*suff[i]

print(ans)