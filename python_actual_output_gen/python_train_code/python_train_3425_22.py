fir = input().split(':')
sec = input().split(':')

ah = int(fir[0])
am = int(fir[1])
bh = int(sec[0])
bm = int(sec[1])

if(ah<bh or(ah==bh and am<bm)):
    ah=ah+24
ah=ah-bh
am=am-bm
if(am<0):
    ah=ah-(-am)/10-1
    am=60+am
print('%02d:%02d'%(ah,am))