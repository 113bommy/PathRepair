n=input()
text=input()
switcher=-1
#b=1
#r=-1
lastbad=0
tries=10000000
triecount=0
triecount2=0
counter=-1
abad1=0
abad2=0
for a in text:
	counter+=1
	switcher*=-1
	
	if a=='r' and switcher==-1:
		abad1+=1
			
		
			
			
	if a=='b' and switcher==1:
		abad2+=1

if abad1>=abad2:
	triecount=abad1
else:
	triecount=abad2


if triecount<tries:
	tries==triecount
tc1=triecount


switcher=-1
abad1=0
abad2=0
for a in text:
	counter+=1
	switcher*=-1
	
	if a=='r' and switcher==-1:
		abad1+=1
			
		
			
			
	if a=='b' and switcher==1:
		abad2+=1

if abad1>=abad2:
	triecount2=abad1
else:
	triecount2=abad2

#print('tc1-'+str(triecount)+'tc2-'+str(triecount2))
tc1=triecount
tc2=triecount2
if tc1<=tc2:
	print(tc1)
else:
	print(tc2)
