k=int(input())
s=input().strip()
print(s if len(s)<=k else s[:k]+'...')