n=int(input())
a='+'+'-'*24+'+'
print(a)


b='|'
if n>=1:b=b+'O.'
else:b=b+'#.'
for i in range(1,11):
    if 3*i+2>n:b+='#.'
    else:b+='O.'
b+='|D|)'
print(b)

b='|'
if n>=2:b=b+'O.'
else:b=b+'#.'
for i in range(1,11):
    if 3*i+3>n:b+='#.'
    else:b+='O.'
b+='|.|'
print(b)



b='|'
if n>=3:b=b+'O.'
else:b=b+'#.'
b=b+'.'*22
b+='|'
print(b)

b='|'
if n>=4:b=b+'O.'
else:b=b+'#.'
for i in range(1,11):
    if 3*i+4>n:b+='#.'
    else:b+='O.'
b+='|.|)'
print(b)




print(a)