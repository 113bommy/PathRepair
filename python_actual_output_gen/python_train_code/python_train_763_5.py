hi, mi = input().split(':')
hf, mf = input().split(':')
hi = int(hi)
mi = int(mi)
hf = int(hf)
mf = int(mf)

d = (hf*60 + mf)  - (hi*60 + mi) 
d//=2

mi += d%60
if mi > 60:
	hi+=1
	mi%=60

hi += (d//60)

print('%02d:%02d'%(hi, mi))
