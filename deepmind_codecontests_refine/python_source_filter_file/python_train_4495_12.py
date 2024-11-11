def main():
	s = input()
	vowels = set(['a','e','i','o','u'])
	ans = ""
	for c in s:
		c = c.lower()
		if c in vowels:
			pass
		else :
			ans += '.'
			ans += c
	print(ans)

if __name__ == '__main__':
	main()