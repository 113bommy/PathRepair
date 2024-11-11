n=int(input())
x=input()
flaga=-1
flagb=-1
flagc=-1
mina=100000
minb=100000
minc=100000
minab=100000
minbc=100000
minca=100000
minabc=100000
if 'A' in x:
	flaga+=1
	mina=int(x[0:x.find(' ')])
if 'B' in x:
	flagb+=1
	minb=int(x[0:x.find(' ')])
if 'C' in x:
	flagc+=1
	minc=int(x[0:x.find(' ')])
if 'A' in x and 'B' in x:
	flaga+=1
	flagb+=1
	minab=int(x[0:x.find(' ')])
if 'B' in x and 'C' in x:
	flagb+=1
	flagc+=1
	minbc=int(x[0:x.find(' ')])
if 'C' in x and 'A' in x:
	flagc+=1
	flaga+=1
	minca=int(x[0:x.find(' ')])
if 'A' in x and 'B' in x and 'C' in x:
	flaga+=1
	flagb+=1
	flagc+=1
	minabc=int(x[0:x.find(' ')])
for i in range(1,n):
	x=input()
	if 'A' in x:
		flaga+=1
		mina=min(int(x[0:x.find(' ')]),mina)
	if 'B' in x:
		flagb+=1
		minb=min(int(x[0:x.find(' ')]),minb)
	if 'C' in x:
		flagc+=1
		minc=min(int(x[0:x.find(' ')]),minc)
	if 'A' in x and 'B' in x:
		flaga+=1
		flagb+=1
		minab=min(int(x[0:x.find(' ')]),minab)
	if 'B' in x and 'C' in x:
		flagb+=1
		flagc+=1
		minbc=min(int(x[0:x.find(' ')]),minbc)
	if 'C' in x and 'A' in x:
		flagc+=1
		flaga+=1
		minca=min(int(x[0:x.find(' ')]),minca)
	if 'A' in x and 'B' in x and 'C' in x:
		flaga+=1
		flagb+=1
		flagc+=1
		minabc=min(int(x[0:x.find(' ')]),minabc)
if flaga!=-1 and flagb!=-1 and flagc!=-1:
	print(min(mina+minb+minc,minabc,minab+min(minc,minca,minbc,minabc),minbc+min(mina,minab,minca,minabc),minca+min(minb,minab,minbc,minabc)))
else:
	print(-1)