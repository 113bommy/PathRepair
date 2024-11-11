def replace(str, charSet):
	for singleChr in charSet:
		pattern = singleChr * (len(str) - 1)
		while len(pattern) > 0:
			str = str.replace(pattern, singleChr)
			pattern = pattern[1:]
	return str

print(int(input()) - len(replace(input(), "RGB")))