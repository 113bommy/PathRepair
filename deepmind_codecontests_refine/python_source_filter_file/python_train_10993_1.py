def seperateints(x):  
    k=''
    l=[]
    for i in x :
        if i==' ' :
            l.append(int(k))
            k=''
            continue 
        k=k+i
    l.append(int(k))   
    return(l)
def luckynum(x):
    for i in x : 
        if i!='4' and i!='7' :
            return False
    return True 
n=int(input())
i=5
while n>=i :
      n-=i
      i+=5
x=i/5
nn=0
k=0
while k<n  :
    k=k+x
    nn+=1
if nn==1  :print('Sheldon')  
elif nn==2 :print('Leonard')  
elif nn==3 :print('Penny')     
elif nn==4 :print('Rajesh')     
elif nn==5 :print('Howard')         