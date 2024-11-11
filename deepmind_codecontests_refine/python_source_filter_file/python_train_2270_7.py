n,k=map(int,input().split())
s=input()
print(s[:k]+s[k].lower()+s[k+1:])