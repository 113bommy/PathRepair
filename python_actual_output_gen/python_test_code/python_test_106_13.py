import sys

n, k = map(int,input("n k: ").split())
for i in range(1,k+1):
	if n % i != i - 1:
		print("No")
		sys.exit()
print("Yes")
sys.exit()