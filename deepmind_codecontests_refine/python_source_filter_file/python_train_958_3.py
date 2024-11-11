n=input()
m=input()
n=" ".join(sorted(n))
for i in range(len(n)):
	if n[i]!="0":
		n=n[i]+n[:i]+n[i+1:]
		break
print(["OK","WRONG_ANSWER"][m!=n])