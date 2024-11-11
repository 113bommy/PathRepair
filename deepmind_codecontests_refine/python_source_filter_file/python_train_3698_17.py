n=int(input())
ch=input()
dict={'G':0,'R':0,'B':0}
for x in ch:
    dict[x]+=1
    if dict['G']!=0 and dict['R']!=0 and dict['B']!=0:
        sol='GRB'
        break

if dict['G']==0 and dict['R']==0:
    sol='B'
    
if dict['B']==0 and dict['R']==0:
    sol='G'

if dict['G']==0 and dict['B']==0:
    sol='R'

if dict['G']==1 and dict['B']==1 and dict['R']==0:
        sol='R'
if dict['G']==1 and dict['R']==1 and dict['B']==0:
        sol='B'
if dict['B']==1 and dict['R']==1 and dict['G']==0:
        sol='G'

if dict['G']==1 and dict['B']>1 and dict['R']==0:
        sol='GR'
if dict['R']==1 and dict['B']>1 and dict['G']==0:
        sol='GR'


if dict['G']==1 and dict['R']>1 and dict['B']==0:
        sol='BG'
if dict['B']==1 and dict['R']>1 and dict['G']==0:
        sol='BG'

    
if dict['B']==1 and dict['G']>1 and dict['R']==0:
        sol='BR'
if dict['R']==1 and dict['G']>1 and dict['B']==0:
        sol='BR'


if dict['R']>1 and dict['G']>1 and dict['B']==0:
        sol='BGR'

if dict['R']>1 and dict['G']==0 and dict['B']>1:
        sol='BGR'

if dict['R']==0 and dict['G']>1 and dict['B']>1:
        sol='BGR'


print(sol)
