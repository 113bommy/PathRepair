if __name__ == '__main__':
	k = int(input())
	if k > 36:
		print(-1)
	else:
		# Only using 8's and 4's
		if k % 2 == 0:
			res = int('8'*int(k/2))
		else:
			res = '8'*int((k-1)/2) + '4'
		print(res)