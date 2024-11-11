n,k=map(int,input().split())
s=input()
print(s[:k]+s[k-1].lower()+s[k+1:])