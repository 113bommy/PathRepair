s = input()
s_list = list(s)
anwer = []
i = 0
while i < len(s_list):
	if s_list[i] == ".":
		anwer.append("0")
		i+=1
	elif s_list[i]=="-" and s_list[i+1]==".":
		anwer.append("1")
		i+=2
	elif s_list[i]=="-" and s_list[i+1]=="-":
		anwer.append("2")
		i+=2
	else:
		i +=1
anwer_s = "".join(anwer)
print(anwer_s)

