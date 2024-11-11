s=input()
n=len(s)
print(max([n-i for i in range(0,n//2,2) if  s[:(n-i)//2]==s[(n-i)//2:-i]]))