S, T = input(), input()
ans = len(T)
for i in range(len(S)-len(T)):
	tmp = 0
	for j in range(len(T)):
		if S[i+j] != T[j]:
			tmp += 1
	ans = min(ans, tmp)
print(ans)