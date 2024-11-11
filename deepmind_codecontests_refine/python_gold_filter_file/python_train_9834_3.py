k=int(input())
i=0
j=0
a=['#']*11
b=['#']*11
d=['#']*11
c=['#']
bus=[a,b,c,d]
while k>0:
    if j==2 and i>0:
        j=j+1
    bus[j][i]="O"
    j=j+1
    if j==4:
        j=0
        i=i+1
    k=k-1
print('+------------------------+')
s='|'
i=0
while i<len(a):
    s=s+a[i]+'.'
    i=i+1
s=s+'|D|)'
print(s)
s='|'
i=0
while i<len(b):
    s=s+b[i]+'.'
    i=i+1
s=s+'|.|'
print(s)
s='|'
i=0
while i<len(c):
    s=s+c[i]+'.'
    i=i+1
s=s+'......................|'
print(s)
s='|'
i=0
while i<len(d):
    s=s+d[i]+'.'
    i=i+1
s=s+'|.|)'
print(s)
print('+------------------------+')

