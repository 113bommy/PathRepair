a=input()
cnt=[0]*10
for i in (1,6,8,9):
	cnt[i]=-1
for i in a:
	cnt[int(i)]+=1
mod = [1869, 1968, 9816, 6198, 1698, 1986, 1896, 1869]
modCnt=0
for i in range(1,10):
	for j in range(cnt[i]):
		modCnt= (modCnt*3 + i)%7
	print(str(i)*cnt[i], end='')
modCnt=(10000*modCnt)%7
print(str(mod[7-modCnt])+'0'*cnt[0])
