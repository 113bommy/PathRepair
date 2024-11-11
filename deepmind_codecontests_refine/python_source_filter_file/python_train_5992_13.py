n = input()
n = int(n)
s = input()
L1 = s.split()
L2 = [i for i in range(1,n+1)]
L3 = list(zip(L1,L2))
L4 = sorted(L3,key=lambda x:x[0])
for i in range(n//2):
	print(L4[i][1],L4[-i-1][1])
