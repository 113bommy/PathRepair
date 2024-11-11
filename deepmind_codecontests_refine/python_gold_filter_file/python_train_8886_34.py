n = int(input())
seq = list(map(str,input().upper()))
S = []
for x in seq:
	S.append(x)

i = 0
count = 0
while(i < n):
	if(i != n-1):
		if(S[i] == S[i + 1]):
			count += 1
	else:
		break
		
	i += 1

print(count)