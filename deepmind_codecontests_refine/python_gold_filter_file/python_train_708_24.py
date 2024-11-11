a,b=map(int,input().split())
s=input().split("-")
print("Yes" if len(s)==2 and len(s[0])==a and len(s[1])==b else "No")