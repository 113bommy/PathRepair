s="3+2+1"

def insertion_sort(l):
    for i in range(1, len(l)):
        j = i-1
        key = l[i]
        while (l[j] > key) and (j >= 0):
           l[j+1] = l[j]
           j -= 1
        l[j+1] = key



l=[]
for i in range(len(s)):
	if s[i]!="+":
		l.append(int(s[i]))

insertion_sort(l)
string=""

for i in range(len(l)):
	if i!=len(l)-1:
		string+=str(l[i])+"+"
	else:
		string+=str(l[i])

print(string)
