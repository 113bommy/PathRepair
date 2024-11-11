k=int(input())
s=input()
if len(s)<=k:
    print(s)
else:
    print(s[1:k+1]+"...")
