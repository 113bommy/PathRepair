s = input()
ns = ""
for i in range(len(s)-1):
	if s[i] == "v" and s[i+1]=="v":
		ns += "w"
	else:
		ns += s[i]
 
print(ns)
w,o =0,0
tot = 0
for i in ns:
    if i == "w":
        tot +=o
        w +=1
    elif i == "o":
        o += w
    print(w,o,tot)
print(tot)