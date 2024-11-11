a,b,c=map(int, input().spilt())
ans= "NO"
for i in range(10):
	if a*i % b == c:
		ans ="YES"
print(ans)