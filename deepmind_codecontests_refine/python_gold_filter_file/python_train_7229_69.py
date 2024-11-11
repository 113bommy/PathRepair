inp = input().split()

n,m = int(inp[0]),int(inp[1])

mini = n;
if m<n:
	mini = m

if mini%2 == 1:
	print ("Akshat")
else:
	print("Malvika")