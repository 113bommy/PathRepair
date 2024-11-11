used = [1]*100

n = int(input())

me = [int(x) for x in input().split(' ')]

for _ in range(n-1):
	ot = [int(x) for x in input().split(' ')]
	used[ot[0]:ot[1]+1] = [0]*(ot[1]-ot[0])

print(sum(used[me[0]:me[1]+1]))
