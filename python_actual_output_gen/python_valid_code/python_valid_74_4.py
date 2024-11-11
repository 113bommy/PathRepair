n = int(input())

s = ""

while n != 0:
	s = str(n%2) + s
	s = -(s//2)

print(s if s != "" else 0)