s = input()
k,n,c = "keyence",len(s),0
for i in range(8):
	if k[:i]==s[:i] and k[i:]==s[n+i-8:]: break
	else: c+=1
if c-8: print("NO")
else: print("YES")