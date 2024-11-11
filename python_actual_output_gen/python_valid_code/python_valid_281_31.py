n , m = [int(i) for i in input().split()]
x = [i for i in input().split()]
y = [i for i in input().split()]
q = int(input())
liste_year = []

for i in range(q):
	liste_year.append(int(input()))

for i in range(q):
	print (str(x[liste_year[i]%n - 1]) + " " + str(y[liste_year[i]%m -1]))