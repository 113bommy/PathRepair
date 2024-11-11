n,k=map(int,input().split())
s=input()
ss=s[k]

print(s[:k]+ss.lower()+s[k+1:])