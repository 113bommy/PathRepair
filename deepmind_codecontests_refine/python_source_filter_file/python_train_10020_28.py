# import sys 
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')
mod = int(1e9)+7
def sp(n):
	if n==1:
		return input()
	else:
		return map(str, input().split())
def np(n):
	if n==1:
		return int(input())
	else:
		return map(int, input().split())
w = ["Ayush", "Ashish"]
for _ in range (0, int(input())):
	n,x = np(2)
	k = 0
	for i in range (0,n-1):
		a,b = np(2)
		if a==x or b==x:
			k += 1
	# l = list(np(2))
	ans = 0
	if k==1:  
		print (w[0])
	else:
		t = ((n-k-1)%2) + (k%2)
		print(w[1-(t%2)])