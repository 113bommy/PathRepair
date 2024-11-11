a=input()
b=input()
c=input()
a1=a[0]+a[1]+' '+a[1]+a[2]+' '+b[0]+b[1]+' '+b[1]+b[2]+' '+c[0]+c[1]+' '+c[1]+c[2]
L=a1.split(' ')
m='impossible'
if L.count('A>')+L.count('<A')==2 :
    
    if L.count('B>')+L.count('<B')==1 and L.count('C>')+L.count('<C')==0  :
        m='CBA'
    elif L.count('C>')+L.count('<C')==1 and L.count('B>')+L.count('<B')==0:
        m='BCA'
    
elif L.count('A>')+L.count('<A')==0 :
    if L.count('B>')+L.count('<B')==1 and L.count('C>')+L.count('<C')==2:
        m='ABC'
    elif L.count('C>')+L.count('<C')==1 and L.count('B>')+L.count('<B')==2:
        m='ACB'
    else :
        m='Impossible'
elif L.count('A>')+L.count('<A')==1 :
    if L.count('B>')+L.count('<B')==2 and L.count('C>')+L.count('<C')==0 :
        m='CAB'
    if L.count('C>')+L.count('<C')==2 and L.count('B>')+L.count('<B')==0 :
        m='BAC'
print(m)