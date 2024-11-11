n,a,b,c,d=map(int,input().split())
s=input()

if "##" in s[a:max(c,d)]:print("No")
elif c>d and "..." not in s[b-1:c+1]:print("No")
else:print("Yes")