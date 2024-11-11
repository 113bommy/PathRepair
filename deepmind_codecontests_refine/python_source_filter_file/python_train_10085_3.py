import re
string = input()
string = re.split(r"[ :,;.]",string)
words=[]
for i in string:
	if 3<=len(i)<6:
		words.append(i)
print(" ".join(words))