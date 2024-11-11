h1,m1=map(int,input().split(':'))
h2,m2=map(int,input().split(':'))
if h1<h2 or (h1==h2 and m1<m2):
    h1+=23
    m1+=60
    h3=h1-h2
    m3=m1-m2
else:
    if m1<m2:
        h1-=1
        m1+=60
        h3=h1-h2
        m3=m1-m2
    else:
        h3=h1-h2
        m3=m1-m2
if m3>=60:
    h3+=1
    m3-=60
if h3==24:
    h3=0
if h3<10:
    h3='0'+str(h3)
if m3<10:
    m3='0'+str(m3)
print('{}:{}'.format(h3,m3))
