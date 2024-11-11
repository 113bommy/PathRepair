

def case():
	a, b, c = map(int, input().split())
	ans = 0

	if a + b * 2 + c * 3 % 2:
		print(1)
	else:
		print(0)

def main():
	T = int(input())
	for _ in range(T):
		case()



	

if __name__ == '__main__':
	main()