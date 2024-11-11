k = int(input())
s = input()
print(s[0:k] + "..." if len(s) > k else s)