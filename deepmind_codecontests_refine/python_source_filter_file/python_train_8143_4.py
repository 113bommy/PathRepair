t=input()
count=0
q=dict()
q['>']='1000'
q['<']='1001'
q['+']='1010'
q['-']='1011'
q['.']='1100'
q[',']='1101'
q['[']='1110'
q[']']='1111'
def chlen(s):
    b=''
    for i in range(len(s)):
        if s[i] in q:
            b+=q.get(s[i])
    return b
f=chlen(t)
for i in range(len(f)):
    count+=int(f[i])*(2**(len(f)-i))/2
print(int(count%1000003))
    