k=int(input())
s=input()

print(s[:k]+'...' if len(s)>k else s)