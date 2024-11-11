s=str(input())
s=s.replace('?','')
s=s.replace(' ','')
d=s[len(s)-1]
if(d in 'aeiou' or d in 'AEIUO'):
    print('YES')
else:
    print("NO")