hh1,mm1= input().split(':')
hh2,mm2= input().split(':')

t1= int(hh1)*60+ int(mm1)
t2= int(hh2)*60+ int(mm2)
hans= (t1+t2)//120
mans= (t1+t2)//2
mans= mans%60

if(hans<9):
    hans= '0'+str(hans)
if(mans<9):
    mans='0'+ str(mans)
print(str(hans)+':'+ str(mans))