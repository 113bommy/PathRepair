n,k=map(int,input().split())
s=input()
print(s[:k]+str.lower(s[k-1])+s[k:])