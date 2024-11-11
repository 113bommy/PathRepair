s = input()
K = int(input())

for i,c in enumerate(s):
	x = ord('z')-ord(c)+1
	if x <= K:
		s = s[:i]+'a'+s[i+1:]
		K -= x

print(s[:-1]+chr((ord(s[-1])-ord('a')+K)%26+ord('a')))