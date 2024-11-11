s=input()
c=s.count('B')
n=0
for i in range(len(s)):
    if s[i]=='B':
        n+=i+1
print(n-c*(c-1)//2)