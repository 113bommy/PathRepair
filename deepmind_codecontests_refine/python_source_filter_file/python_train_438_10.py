from sys import stdin

def solve():
	return

def main():
	inp=stdin.readline
	for _ in range(int(inp())):
		n=int(inp())
		a=list(map(int, inp().split()))
		d=set()
		ans=True
		for i in range(n+1):
			k=i+a[i%n]
			if k in d:
				ans=False
				break
			d.add(k)
		
		if ans:
			print("YES")
		else:
			print("NO")
	

main()