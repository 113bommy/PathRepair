n=int(input())
ans=[0,0,0]
t=[]
t+=map(int,input().split())
for i in range(n):
	ans[i//3]+=t[i]
if ans[0]>ans[1] and ans[0]>ans[2]:
	print('chest')
elif ans[1]>ans[2]:
	print('biceps')
else:
	print('back')