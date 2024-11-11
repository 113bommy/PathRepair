
n,k=map(int,input().split())
s=input()
s = s[:k-1]+str(s[k]).lower()+s[k+1:]
print(s)