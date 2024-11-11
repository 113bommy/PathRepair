n,m=map(int,input().split())
s=input()
t=input()
if "*" in s:
    a,b=s.split("*")
    if t.startswith(a) and t[len(s[1]):].endswith(b):
        print("YES")
    else:
        print("NO")
else:
    if s==t:
        print("YES")
    else:
        print("NO")

