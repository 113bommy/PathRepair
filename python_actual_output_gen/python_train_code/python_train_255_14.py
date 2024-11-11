a,b=map(int,input().split())
s=input()
if s.count('-') and s[a]=='-' and len(s)==a+b+1:
    print('Yes')
else:
    print('No')