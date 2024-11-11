def get(summ):
	return str(summ%9) + '9'*int(summ//9)

for t in range(0,int(input())):
	n,k = map(int,(input().split()))

	result = -1

	for last_digit in range(10):
		
		last_digit_sum = 0
		for i in range(k+1):
			last_digit_sum += (last_digit + i) % 10

		if last_digit_sum > n: continue

		if last_digit + k >= 10:
			for cnt9 in range(15):
				sum9 = 9 * cnt9 * (10 - last_digit)

				if sum9 > n - last_digit_sum: break
				for first_digt in range(9):
					first_digit_sum = (10-last_digit)*first_digt + (k-9+last_digit)*(first_digt+1)

					f = first_digit_sum + sum9 + last_digit_sum

					if n >= f: 
						remain = n - f
						if remain % (k + 1) == 0:
							pres = int(get(remain//(k+1)) + str(first_digt) + '9'*int(cnt9) + str(last_digit))
							if(result == -1): result = pres
							else: result = min(result,pres)

		elif (n - last_digit_sum) % (k + 1) == 0:
			pres = int(get((n - last_digit_sum)//(k + 1)) + str(last_digit))
			if(result == -1): result = pres
			else: result = min(result,pres)

	print(result)