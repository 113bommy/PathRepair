# (c) midandfeed aka asilentvoice
k = 1
n = int(input())
q = []
while( ((pow(2, k)-1)*(pow(2, k-1))) <= n ):
	q.append(((pow(2, k)-1)*(pow(2, k-1))))
	k += 1
for i in range(len(q)-1, -1, -1):
	if n%q[i] == 0:
		print(q[i])
# print(q)