n,a,b,c,d=map(int,input().split())
s=input()
#s=s[a:max(c,d)+1]
if ("##" in s[a:max(c,d)+1]) or (c>d and "..." not in s[b-1:d+2]):
    print("No")
else:
    print("Yes")