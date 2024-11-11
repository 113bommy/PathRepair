seq = input()
maxx = 0
if seq.count("a") > len(seq)/2:
	maxx = len(seq)
else:
	maxx = seq.count("a") + 1
print(maxx)
