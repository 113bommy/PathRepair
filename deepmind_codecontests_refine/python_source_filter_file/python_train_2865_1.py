
def main():
	
	name = input()
	substring = input()
	count = 0
	
	i = 0
	while(i + len(substring) < len(name)):
		
		if name[i] == substring[0]:
			differ = False
			for j in range(len(substring)):
				if substring[j] != name[j+i]:
					differ = True
					break
			if not differ:
				count += 1
				i += len(substring) - 1
		i+=1
	print(count)		 
	return 0

if __name__ == '__main__':
	main()

