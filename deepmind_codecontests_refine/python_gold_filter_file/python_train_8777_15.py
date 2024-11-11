

def solve():  # n = a^x + b*b , hence  n is in the set if (n - a^x) % b == 0
	n,a,b = map(int,input().split())
	if a == 1:
		if (n-1)%b ==0:
		
			print("YES")
		else:
			print("NO")
	else:
		curr = 1
		flag = 0
		while curr<=n :
			if curr%b==n%b:
				flag=1
				break
			curr *=a

		if flag == 1:
			print("YES")
		else:
			print("NO")


tests = int(input())
for _ in range(tests):
	solve()