s=input()
f1=f2=0
if(len(s)%2==0):
    f1=1
if(s[0]==s[len(s)-1]):
    f2=1
    
if((f1==1 and f2==0) or (f1==0 and f2==1)):
    print('Second')
else:
    print('First')