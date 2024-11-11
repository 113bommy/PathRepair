a=[]
shet=0
i=0
log = str(input())
kol = int(input())
len_log = len(log)
log=log.lower()
log = log.replace('0','o')
log = log.replace('1','i')
log = log.replace('l','i')
while i < kol:
    a=str(input())
    a=a.lower()
    a = a.replace('0','o')
    a = a.replace('l','i')
    a = a.replace('1','i')
    if log==a:
        #print(log+'='+a)
        shet+=1
    else:
        #print(log+'='+a)
        shet+=0
    i+=1
if shet>0:
    print('No')
else:
    print('Yes')
