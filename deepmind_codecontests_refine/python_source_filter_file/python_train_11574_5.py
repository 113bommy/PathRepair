def is_vowel(c):
	return c == "a" or c == "e" or c == "i" or c == "o" or c == "u"

def count_vowels(word):
	ans = 0
	last_vowel = ""

	for i in range(len(word)):
		if is_vowel(word[i]):
			last_vowel = word[i]
			ans += 1

	return ans, last_vowel


if __name__ == "__main__":
	N = int(input())
	m = {}
	for n in range(N):
		word = input()
		num_vowels, last_vowel = count_vowels(word)
		
		if not num_vowels in m:
			m[num_vowels] = {}
		if not last_vowel in m[num_vowels]:
			m[num_vowels][last_vowel] = []
		
		m[num_vowels][last_vowel].append(word)

	tot_pair = []
	semi_pair = []

	for key_num, value_num in m.items():
		for key_last, value_last in value_num.items():
			while len(value_last) >= 2:
				tot_pair.append(value_last[-1])
				tot_pair.append(value_last[-2])
				value_last.pop()
				value_last.pop()
			while len(value_last) > 0:
				semi_pair.append(value_last[0])
				value_last.pop()
		if len(semi_pair) % 2 == 1:
			semi_pair.pop()
	
	ans = []
	count = 0

	while len(tot_pair) >= 2 and len(semi_pair) >= 2:
		line_1 = [semi_pair[-1], tot_pair[-1]]
		line_2 = [semi_pair[-2], tot_pair[-2]]
		semi_pair.pop()
		semi_pair.pop()
		tot_pair.pop()
		tot_pair.pop()
		lyric = [line_1, line_2]
		ans.append(lyric)
		count += 1

	while len(tot_pair) >= 4:
		line_1 = [tot_pair[-1], tot_pair[-2]]
		line_2 = [tot_pair[-3], tot_pair[-4]]
		tot_pair.pop()
		tot_pair.pop()
		tot_pair.pop()
		tot_pair.pop()
		lyric = [line_1, line_2]
		ans.append(lyric)
		count += 1

	print(count)
	for lyric in ans:
		for line in lyric:
			print(line[0], line[1])