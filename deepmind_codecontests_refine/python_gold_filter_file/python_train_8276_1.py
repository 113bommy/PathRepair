s=input()
t=s[0:2]
q=s[3:5]
t1=int(t)
q1=int(q)
z=int(input())
t1=t1+z//60;
q1=q1+z%60;
if(q1>=60):
    t1=t1+q1//60;
    q1=q1%60;
    t1=t1%24;
t1=t1%24
if(t1<10):
    t='0'+str(t1)
else:
    t1=t1%24;
    t=str(t1)
if(q1<10):
    q1=q1%60
    q='0'+str(q1)
else:
    q=str(q1)
x=t+":"+q
print(x)

    
