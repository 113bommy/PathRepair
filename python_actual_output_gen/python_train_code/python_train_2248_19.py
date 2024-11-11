# Premdeep Doriya
# aka pdoriya68

nm = list(map(int, input().split(" ")));
n = nm[0];
m = nm[1];

hno = list(map(int, input().split()));

ch = 1;
t = 0;
for i in range(m):
	dh = hno[i];

	if dh < ch:
		t += (ch - 1) + (dh - 1);
	else:
		t += (dh - ch);

	ch = hno[i];

print(t);