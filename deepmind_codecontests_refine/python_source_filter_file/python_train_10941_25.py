a=[]
b=[]
c=[]
abc=[]
ab=[]
bc=[]
ac=[]
final=[]
n=int(input())
for i in range(0,n):
    x,y=input().split()
    if y=='A':
        a.append(int(x))
    if y=="B":
        b.append(int(x))
    if y=="C":
        c.append(int(x))
    if y=="ABC" or y=="BAC" or y=="BCA"or y=="ACB" or y=="CAB" or y=="CBA":
        abc.append(int(x))
    if y=="AB"or y=="BA":
        ab.append(int(x))
    if y=="CA" or y=="AC":
        ac.append(int(x))
    if y=="BC"or y=="CB":
        bc.append(int(x))
if len(a)!=0 and len(b)!=0 and len(c)!=0:        
    final.append(min(a)+min(b)+min(c))
if len(a)!=0 and len(bc)!=0 :
    final.append(min(a)+min(bc))
if len(abc)!=0:
    final.append(min(abc))
if len(b)!=0 and len(ac)!=0:
    final.append(min(b)+min(ac))
if len(c)!=0 and len(ac)!=0:
    final.append(min(c)+min(ac))
if len(ab)!=0 :
    if (len(bc)!=0):
        final.append(min(ab)+min(bc))
    if  len(ac)!=0:
        final.append(min(ab)+min(ac))
if len(bc)!=0:
    if (len(ab)!=0 ):
        final.append(min(ab)+min(bc))
    if len(ac)!=0 :    
        final.append(min(bc)+min(ac))    
if len(ac)!=0  :
    if len(bc)!=0 :
        final.append(min(ac)+min(bc))
    if len(ab)!=0:
        final.append(min(ab)+min(ac))    
if len(final)!=0:
    print(min(final))    
else:
    print(-1)
    