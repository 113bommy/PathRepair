n=input()
a=0
b=0
p=n.index('^')
for i in range(len(n)):
    if i<p and n[i]!='=':
        a+=(p-i)*int(n[i])
    if i>p and n[i]!='=':
        b+=(i-p)*int(n[i])
res=['left','balance','right']
if a<b:
    print(res[0])
elif a==b:
    print(res[1])
else:
    print(res[2])