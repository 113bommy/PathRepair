k=input()
s=list(input())
x,y,z=list('qwertyuiop'),list('asdfghjkl;'),list('zxcvbnm,./')
v=1 if k=='L' else -1
c=[x,y,z]
i=0
t=''
while i<len(s):
    if s[i] in x:a=x
    if s[i] in y:a=y
    if s[i] in z:a=z
    a=a[a.index(s[i])+v]
    t=t+a
    i=i+1

