import sys
input = sys.stdin.readline

n = int(input())
st = input()
st_strip = st.strip(".")

s, end = 0, 0
once = True
if "L" in st and "R" in st:
	for i in range(n):
		if once and st[i] == "R":
			s = i
			once = False
		if st[i] == "R" and st[i+1] == "L":
			end = i
elif st_strip[0] ==  "L":
	for i in range(n):
		if once and st[i] == "L":
			once = False
			end = i
		if st[i] == "L": s = i-1
else:
	for i in range(n):
		if once and st[i] == "R":
			once = False
			s = i
		if st[i] == "R": end = i+1

print(s+1, end+1)