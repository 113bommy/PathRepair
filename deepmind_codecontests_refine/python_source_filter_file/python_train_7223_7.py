def main():
	n = int(input())
	for i in range(n):
		s = input()
		if s.endswith("lala.") and s.endswith("miao.", 0, 4):
			print("OMG>.< I don't know!")
		elif s.endswith("lala."):
			print("Freda's")
		elif s.endswith("miao.", 0, 4):
			print("Rainbow's")
		else:
			print("OMG>.< I don't know!")

if __name__ == '__main__': main()
