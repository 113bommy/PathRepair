n = int(input())
l = list(map(int,input().split()))
odd_pos = []
odd_neg = []
even_pos = []
even_neg = []
for i in range(len(l)):

	if l[i]%2 == 1 and l[i] > 0:
		odd_pos.append(l[i])
	elif l[i]%2 == 0 and l[i] > 0:
		even_pos.append(l[i])
	elif l[i]%2 == 1 and l[i] < 0:
		odd_neg.append(l[i]) 
	else:
		even_neg.append(l[i])

if len(odd_pos):
	
	odd_pos.sort(reverse=True)
	if len(odd_pos)%2 == 0:
		if len(odd_neg):
			t = max(odd_pos[-1]+max(odd_neg),0)
			# odd_pos = odd_pos[:len(odd_pos)-1] 
		else:
			t = 0
		odd_pos = odd_pos[:len(odd_pos)-1]
		ans1 = sum(odd_pos) + t
	else:
		ans1 = sum(odd_pos)
	if len(even_pos):
		ans2 = sum(even_pos)
	else:
		ans2 = 0
	print(ans1 + ans2)
elif len(odd_neg):
	ans1 = max(odd_neg)

	if len(even_pos):
		ans2 = sum(even_pos)
	else:
		ans2 = 0
	print(ans1+ans2)