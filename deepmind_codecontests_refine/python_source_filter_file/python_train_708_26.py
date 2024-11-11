a,b=map(int, input().split())
s=input().split("-")
print("Yes" if len(s)==2 and len(s[0]) and len(s[1]) else "No")