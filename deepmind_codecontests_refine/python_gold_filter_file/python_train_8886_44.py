n=int(input())
s=input()
c=0
for i in range(n-1):
    if s[i]==s[i+1]:
        c=c+1
    else:
        pass
print(c)