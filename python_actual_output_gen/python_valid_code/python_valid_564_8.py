t = int(input())

for i in range(t):
	n =  int(input())
	N = int(input())
	r = 0


	while N > 10:
		last_digit = N%10
		N-=last_digit

		N = int(str(N)[1:-1] + str(N)[0])
		r+=last_digit+1
	if 0<N<10:
		r+=N
	print(r)

