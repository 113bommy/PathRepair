s=input()
c=s.count('W')
n=0
for i in range(len(s)):
    if s[i]=='W':
        n+=i+1
print(n-c*(c+1)//2)