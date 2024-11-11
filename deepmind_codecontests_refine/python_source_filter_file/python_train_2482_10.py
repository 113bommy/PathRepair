S = input()
T = input()

ans = ["UNRESTORABLE"]
for i in range(len(S)-len(T)+1):
	count = 0
	for j in range(len(T)):
		if (S[i+j] == T[j] or S[i+j] == "?"):
			count += 1
	if count == len(T):
		S = S[:i]+T+S[i+len(T):]
		pl = S.replace("?","a")
		ans.append(pl)

print(ans[-1])