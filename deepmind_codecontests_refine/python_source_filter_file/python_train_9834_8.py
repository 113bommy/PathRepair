n=int(input())
a='+'+'-'*24+'+'
print(a)


b='|'
if n>=1:b=b+'0.'
else:b=b+'#.'
for i in range(1,11):
    if 3*i+2>n:b+='#.'
    else:b+='0.'
b+='|D|)'
print(b)

b='|'
if n>=2:b=b+'0.'
else:b=b+'#.'
for i in range(1,11):
    if 3*i+3>n:b+='#.'
    else:b+='0.'
b+='|.|'
print(b)



b='|'
if n>=3:b=b+'0.'
else:b=b+'#.'
b=b+'.'*22
b+='|'
print(b)

b='|'
if n>=4:b=b+'0.'
else:b=b+'#.'
for i in range(1,11):
    if 3*i+4>n:b+='#.'
    else:b+='0.'
b+='|.|)'
print(b)




print(a)