n = int(input())
s = str(input())
A = []
for i in s:
	A.append(ord(i))
for i in range(n-1):
	if A[i] > A[i+1]:
		print("YES")
		print(str(i+1) + " "+ str(i+2))
		break
print ("NO")


