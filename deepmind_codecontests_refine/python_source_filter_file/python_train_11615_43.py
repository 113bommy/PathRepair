x=int(input())
ch=input().split(":")
h=int(ch[0])
m=int(ch[1])
res=""
if x==12:
    if h>12:
        if ch[0][1]=="0":
            res="10"
        else:
            res="0"+ch[0][1]
    elif h<1:
        res="01"
    else:
        res=ch[0]
else:
    if h>24:
        if ch[0][1]=="0":
            res="10"
        else:
            res="0"+ch[0][1]
    elif h<0:
        None
    else:
        res=ch[0]

if m>59:
    if ch[1][1]=="0":
        res=res+":"+"10"
    else:
        res=res+":"+"0"+ch[1][1]
else:
    res=res+":"+ch[1]

print(res)
