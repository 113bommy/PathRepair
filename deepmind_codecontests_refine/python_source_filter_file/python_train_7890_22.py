n=int(input())
s=list(input())
k=int(input())
for i in range(n):
    if s[i]!=s[k]:
        s[i]='*'
print(''.join(s))