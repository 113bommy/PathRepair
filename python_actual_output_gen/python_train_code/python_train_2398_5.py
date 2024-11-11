n=int(input())
def genPrimeList(n):
	isPrime = ["1" for i in range(n + 1)]
	for i in range(2, n + 1):
			for j in range(2 * i, n + 1, i):
				isPrime[j] = "2"
	return isPrime 
if n<4:
    print ("1")
    for x in genPrimeList(n)[2:]:
        print (x, end=' ')
else:
    print ("2")
    for x in genPrimeList(n)[2:]:
        print (x, end=' ')