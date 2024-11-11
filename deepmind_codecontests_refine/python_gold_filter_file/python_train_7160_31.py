s=input()
n=len(s)
a=s[:(n-1)//2]
b=s[(n+1)//2:]
if(a==a[::-1] and a==b): print("Yes")
else: print("No")
