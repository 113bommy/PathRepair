s = list(input().strip())
dead = {'R':0,'Y':0,'B':0,'G':0} 
for i in range(len(s)):
	if s[i] == '!':
		for j in range(i%4, len(s), 4):
			if s[j] != '!':
				s[i] = s[j]
				dead[s[j]] += 1
				break
print(*dead.values())