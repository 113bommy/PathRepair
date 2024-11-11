a=input()
b=[False]*3
for k in a:
    if '0'<=k<='9':
        b[0]=True
    if  'A'<=k<='Z':
        b[1]=True
    if 'a'<=k<'z':
        b[2]=True
if len(a)>=5 and b[0] and b[1] and b[2]:
    print('Correct')
else:
    print('Too weak')