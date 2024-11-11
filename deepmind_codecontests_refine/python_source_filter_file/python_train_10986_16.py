n = int(input())
lst = list(map(int, input().split()))
if n != 1:
	maxx = -1
	for i in range(0, n):
		if (i == 0 and lst[i] > lst[i+1]) or (i == n-1 and lst[i] > lst[i-1]) or (i != 0 and i != n-1 and lst[i] >= lst[i-1] and lst[i] >= lst[i+1]):
			cnt, cnt1 = 0, 0
			for j in range(i, 0, -1):
				if lst[j] >= lst[j-1]:
					cnt += 1
				else: break
			for j in range(i, n-1):
				#print("a", lst[j], lst[j+1])
				if lst[j] >= lst[j+1]:
					cnt1 += 1
				else: break
			maxx = max(maxx, cnt+cnt1+1)
	print(maxx)
else:
	print(1)

