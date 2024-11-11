

n = int(input())

t = input()

word =''

para=''
u=[]
y=[]
o=0


for i in t:
    if i=='(':
        o=1
    elif i==')':
        o=0
        
    if o==1:
        if i!='(':
            para+=i
        if len(word)>0:
            y.append(word.split('_'))
        word=''
    else:
        if len(para) > 0:
            u.append(para.split('_'))
        para = ''
        if i!=')':
            word+=i


if len(word) >0:
    y.append(word.split('_'))
b=0
for i in u:
    b+= len(i)-i.count('')


a=0

for j in y:
    for k in j:
        if len(k) > a:
            a = len(k)

print(a,b)
    
