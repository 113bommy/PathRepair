n=int(input())
a = list(map(int, input().split()))
a.sort()
cnt=1
ans=n+1
for i in a:
	if i==cnt:
		cnt+=1
	else:
		ans=cnt
		break
print(ans)