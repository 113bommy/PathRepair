n = int(input())
a1 = list(map(int,input().split()))
a2 = list(map(int,input().split()))

m = 0

for i in range(n):
	m = max(m, sum(a1[0:i+1])+sum(a2[i:0]))
	
print(m)