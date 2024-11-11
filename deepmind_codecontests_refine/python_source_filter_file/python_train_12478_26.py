import sys

N = int(input())

a = input()
b = input()

for i in range(N):
	if(a[0:N-i] == b[i:N]){
		print(N+i)
		sys.exit()
		
print(2 * N)