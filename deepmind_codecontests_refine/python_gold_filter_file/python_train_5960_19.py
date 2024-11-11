n,m,k = map(int,input().split())
r = "L"*(m-1) + "U"*(n-1)
for i in range(k):
	g,h = map(int,input().split())
for j in range(k):
	g,h = map(int,input().split())
for i in range(n):
	for j in range(m-1):
		# print(i,j)
		if i%2==0:
			# print("R", end=" ")
			r += "R"
		else:
			# print("L",end=" ")
			r += "L"
	r += "D"
	# print("D")
print(len(r))
print(r)