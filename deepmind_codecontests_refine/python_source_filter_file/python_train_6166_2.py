def isPalindrome(s):
	L = len(s)
	for i in range(0, L):
		if (s[i] != s[L - i - 1]):
			return -1
	
	return L

n, m = map(int, input().split())
L = []
pal_left = ""
pal_center = ""
len_pal_center = 0
pal_right = ""

for i in range(n):
	L.append(input())

used = [0]*n

for i in range(n):
	b = L[i][::-1]
	for j in range(i + 1, n):
		if (b == L[j] and used[j] == 0):
			used[j] = 1
			used[i] = 1
			pal_left = pal_left + L[i]
			pal_right = L[j] + pal_right

for i in range(n):
	if (used[j] == 0 and isPalindrome(L[i]) > len_pal_center):
		len_pal_center = len(L[i])
		pal_center = L[i]

palindrome = pal_left + pal_center + pal_right

print(len(palindrome))
print(palindrome)

