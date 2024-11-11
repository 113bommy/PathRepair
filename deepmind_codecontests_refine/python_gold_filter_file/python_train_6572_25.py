n=int(input())
s=[]
a=0
for _ in range(n):
    s.append(input())
for i in range(1,n-1):
    for j in range(1,n-1):
        if s[i][j]==s[i-1][j-1]==s[i-1][j+1]==s[i+1][j-1]==s[i+1][j+1]=='X':
            a+=1
print(a)