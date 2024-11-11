n=int(input())

count=list(map(int,input().split()))
vowel=('a','e','i','o','u')
for i in range(n):
	loc=0
	st=input()
	for ch in st:
		if ch in vowel:
			loc+=1
	if loc!=count[i]:
		print ("NO")
		exit()
print("YES")