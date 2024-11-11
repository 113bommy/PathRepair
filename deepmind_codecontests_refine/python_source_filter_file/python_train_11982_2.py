ch=input()

p=ch.find('20')
if p==-1 :
    p=len(ch)
a=ch[0:p].count('0')
b=ch.count('1')

st='0'*a+'1'*b+ch[p:].replace('1','')



print(st)   
