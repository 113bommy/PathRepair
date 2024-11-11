n = int(input())

to_19 = ['zero','one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
tens = ['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']

if n in range(0,20):
	print(to_19[n-1])
else:
	if n % 10 == 0:
		print(tens[n//10 - 2])
	else:
		n = list(str(n))
		print(tens[int(n[0]) - 2] + '-' + to_19[int(n[1])])



