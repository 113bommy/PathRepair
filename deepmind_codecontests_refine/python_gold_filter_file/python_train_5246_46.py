n = int(input())
m = input()
s = 0
t = 0
flg = 0
flgm = 0
for i in range(n):
	if m[i] == "R":
		if flg == 0:
			s = i+1
			flg = 1
	if m[i] == "L":
		if flgm == 0:
			t = i
			flgm = 1
if t == 0:
	t = m.rfind("R")+2
if s == 0:
	s = m.find("L")+1
print (s,t)