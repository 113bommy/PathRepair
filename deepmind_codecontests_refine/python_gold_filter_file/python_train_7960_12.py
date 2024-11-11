n = int(input())
a = input()
cnt = [0 for i in range(10)]

for i in a:
	if int(i)==9:
		cnt[7]+=1
		cnt[3]+=2
		cnt[2]+=1
	elif int(i) == 8:
		cnt[2]+=3
		cnt[7]+=1
	elif int(i) == 6:
		cnt[3]+=1
		cnt[5]+=1
	elif int(i)==4:
		cnt[3]+=1
		cnt[2]+=2
	else:
		cnt[int(i)] += 1

ans = ''
for i in range(8):
	while(cnt[9-i]>0):
		cnt[9-i]-=1
		ans+=str(9-i)
print(ans)
