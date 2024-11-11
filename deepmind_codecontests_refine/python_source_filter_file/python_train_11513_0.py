n, k = map(int, input().split())
l = "abcdefghijklmnobqrstuvwxyz"
 
a = ""
for i in range(n):
	a = a + l[i%k]
print(a)