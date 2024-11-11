n=input()

n=n.replace('dot','.')
if n[0]=='.':
    n='dot'+n[1:]
if n[-1]=='.':
    n=n[0:-1]+'dot'
n=n.replace('at','@',1)
if n[0]=='@':
    n='at'+n[1:].replace('at','@',1)

print(n)