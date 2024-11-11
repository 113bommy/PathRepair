def main():
	
	v = []
	for i in range(3):
		v.append(input())

	m = {'A': 0, 'B': 0, 'C': 0} # A B C
	for s in v:
		if s[1] == '<':
			m[s[2]] += 1
		else:
			m[s[0]] += 1
	
	if set(m.values()) == 3:
		print(''.join(sorted(m, key=lambda k: m[k])))
	else:
		print('Impossible')
	

if __name__ == '__main__':
	main()


