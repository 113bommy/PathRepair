def f(s):
	i=s.index(".")
	if s[i-1]=="9":
		return "GOTO Vasilisa."
	if int(s[i+1])<5:
		return s[:i]
	else:
		return int(s[:i])+1
s=input()
print(f(s))