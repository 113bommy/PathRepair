n = int(input())
b = list(map(int,input().split()))
if n<3:
	print(0)
	print(*b)
else:
	out =0
	ans =[]
	b.sort()
	k = b[:n//2]
	l = b[n//2:]
	if n%2:
		for i in range(n//2):
			ans.append(l.pop())
			ans.append(k.pop())
		ans.append(l.pop())
		for i in range(1,n,2):
			if ans[i]<ans[i-1] and ans[i]<ans[i+1]:
				out+=1
		print(out)
		print(*ans)
	else:
		for i in range(len(k)):
			ans.append(k.pop())
			ans.append(l.pop())
		for i in range(2,n,2):
			if ans[i]<ans[i-1] and ans[i]<ans[i+1]:
				out+=1
		print(out)
		print(*ans)