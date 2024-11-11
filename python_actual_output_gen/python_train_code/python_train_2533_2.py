N = int(input())
S = input()
found = set()
for i in range(len(S)):
	k = S[i]
	if(not (k in found)):
		found.add(k)
if(len(found)>=N):
	print("YES")
	ptr1 = 0
	count = 0
	found.remove(S[ptr1])
	for i in range(len(S)):
		#print (found)
		if(count==N-1):
			print(S[ptr1:])
			break
		if(i>0 and (S[i] in found)):
			print(S[ptr1:i])
			ptr1=i
			count+=1
			found.remove(S[ptr1])
else:
	print("NO")