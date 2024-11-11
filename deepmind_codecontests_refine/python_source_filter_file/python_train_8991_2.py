a = input()
ans=[]
t=''
qoute =0
space =0
start =1 if a[0]=='"' else 0
for i in range(len(a)):
    v= a[i]
    if start:
        if t=='':
            if v=='"':
                qoute+=1
                t = '<'
            elif v==' ':
                pass
            else:
                space+=1
                t='<'+v
        elif qoute>0:
            if v =='"':
                t+='>'
                qoute=0
                ans.append(t)
                t=''
                start=0
            else:
                t+=v
        else:
            if v ==' ':
                if t!='<':
                    t+='>'
                    ans.append(t)
                    t=''
                    start=0
            else:
                t+=v
    else:
        if v==' ':
            start=1
        elif v=='"':
            start=1
            t='<'
            qoute=1
        else:
            t='<'+v
            start=1
if a[-1]!='"':
    t+='>'
    ans.append(t)
for v in ans:
    print(v)