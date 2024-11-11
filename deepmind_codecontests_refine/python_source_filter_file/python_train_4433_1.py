n = int(input())
z = n//4
s = input()
a = s.count("A")
c = s.count("C")
g = s.count("G")
t = s.count("T")
q = s.count("?")

if a>z or c>z or g>z or c>z:
	print("===")
elif n%4!=0:
	print("===")
else:
	s = list(s)
	for i in range(n):
		if s[i] == "?":
			if a<z:
				s[i]="A"
				a+=1
			elif c<z:
				s[i]="C"
				c+=1
			elif g<z:
				s[i]="G"
				g+=1
			else:
				s[i]="T"
				t+=1
	print(*s, sep='')
