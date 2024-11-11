import sys

s = sys.stdin.readline().strip()
cont = 0
for x in range(len(s)):
	if s[x]=='a' or s[x]=='e' or s[x]=='i' or s[x]=='o' or s[x]=='u' or s[x]=='0' or s[x]=='2' or s[x]=='4' or s[x]=='6' or s[x]=='8':
		cont=cont+1
print (cont)
