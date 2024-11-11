n = int(input())

X = input().split()
Y = input().split()

dict_X = {int(X[0]):list(map(int , X[1:]))}
dict_Y = {int(Y[0]):list(map(int , Y[1:]))}


def main():
	levels = []
	for value in dict_X.values():
		for va in value:
			levels.append(va)
	for value in dict_Y.values():
		for va in value:
			levels.append(va)
	s_levels = list(set(sorted(levels)))
	for num in range(1,n+1):
		if len(s_levels) == n:
			if num != s_levels[num-1]:
				print("Oh, my keyboard")
				break
		else:
			print ("Oh, my keyboard")
			break
	else:
		print ("I become the guy")


if __name__ == "__main__":
	main()



