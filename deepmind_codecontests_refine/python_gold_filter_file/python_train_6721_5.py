a=int(input())
b=input()
tot=0
if b[0]=='<':
    ind=b.find('>')
    if ind==-1:
        tot+=a
    else:
        tot+=b.find('>')
if b[-1]=='>':
    ind=a-b[::-1].find('<')
    if ind==a+1:
        tot+=a
    else:
        tot+=a-ind
print(tot)
