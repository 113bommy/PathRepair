k=int(input())
if k>36:
	print(-1)
else:
	print((k//2)*'8'+(k%2)*'9')
