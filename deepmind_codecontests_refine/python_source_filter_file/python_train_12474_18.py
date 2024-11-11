s=input()
d=""
n=int(input())
for i in range((len(s)+2)//3):
	d+=s[i*3]
print(d)