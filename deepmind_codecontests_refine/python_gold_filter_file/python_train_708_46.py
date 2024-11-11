a,b=map(int, input().split())
s=input()
print("Yes" if s[a]=="-" and s.replace("-","0",1).isdigit() else "No")