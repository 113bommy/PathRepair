import sys
input = sys.stdin.readline
print = sys.stdout.write
n = int(input())
two = [0] * (10**6+20)
for i in map(int,input().split()):
	two[i]+= 1
res = 0
for i in range(10**6+19):
	two[i + 1]+= two[i] // 2
	two[i] %=2
	res+= two[i]
print(str(res))
