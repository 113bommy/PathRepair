k = int(input())
s = input()
print(s[:7]+'...' if len(s)>=k else s)