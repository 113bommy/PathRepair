from sys import stdin


def main():
	k1, k2, k3 = map(int, stdin.readline().split())
	if k1 == 1 or k2 == 1 or k3 == 1:
		print("YES")
	elif k1 == 3 and k2 == 3 and k3 == 3:
		print("YES")
	else:
		cnt = 0
		if k1 == 2:
			cnt += 1
		if k2 == 2:
			cnt += 1
		if k3 == 2:
			cnt += 1
		if cnt >= 2:
			print("YES")
		elif cnt == 1:
			cnt4 = 0
			if k1 == 4:
				cnt4 += 1
			if k2 == 4:
				cnt4 += 1
			if k3 == 4:
				cnt4 += 1
			if cnt4 == 2:
				print("YES")
			else:
				print("NO")
		else:
			print("NO")
			

if __name__ == '__main__':
	main()
