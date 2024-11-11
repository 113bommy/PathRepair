n1 = input()
n2 = input()
h1 = int(n1[:2])
m1 = int(n1[3:])
h2 = int(n2[:2])
m2 = int(n2[3:])

h3 = (h1+h2)//2
m3 = (m1+m2)//2
if (h1+h2)%2 != 0:
    m3 += 30
if m3 == 60:
    h3 += 1
    m3 = 0
if h3 < 10:
    if m3 < 10:
        s ='0'+ str(h3)+':'+'0'+str(m3)
    else:
        s  ='0'+ str(h3)+':'+str(m3)
else:
    if m3 < 10:
        s = str(h3)+':'+'0'+str(m3)
    else:
        s =str(h3)+':'+str(m3)    
print(s)