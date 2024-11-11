hh,mm=map(int,input().split(':'))
mm_aj=int(input())

hh=hh+(mm+mm_aj)//60
mm=(mm+mm_aj)%60

if hh>=24:
    hh=hh%24
if (hh>=10)    :
    if (mm>=10):
        print(str(hh)+':'+str(mm))
    else:
        print(str(hh)+':0'+str(mm))
else:
    if (mm>=10):
        print('0'+str(hh)+':'+str(mm))
    else:
        print('0'+str(hh)+':0'+str(mm))   
