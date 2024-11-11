n=int(input())
s=input()
cnt=s.count('x')-s.count('X')
print(abs(cnt/2))
s=list(s)
for i in range(len(s)):
    if cnt>0 and s[i]=='x':
        s[i]='X'
        cnt-=2
    elif cnt<0 and s[i]=='X':
        s[i]='x'
        cnt+=2
print(''.join(s))