s=input()
t=input()
cth=sth=ctm=stm=''
for i in range(0,5):
    if i<2:
        cth+=s[i]
        sth+=t[i]
    elif i>2:
        ctm += s[i]
        stm+=t[i]
ah=int(cth)-int(sth)
am=int(ctm)-int(stm)
if ah>0 and am<0:
    ah=ah-1
if cth==sth and ctm<stm:
    ah=23
if ah<0 and am>=0:
    ah=24+ah
if ah<0 and am<0:
    ah=23+ah
if am<0:
    am=60+am
if len(str(ah))==1 and len(str(am))==1:
    print("0",ah,":","0",am,sep='')
elif len(str(ah))==1 and len(str(am))==2:
    print("0",ah,":",am,sep='')
elif len(str(ah))==2 and len(str(am))==1:
    print(ah,":","0",am,sep='')
else:
    print(ah,":",am,sep='')