ac=list(input())
r={}
tr1=True
tr2=False
for i in range(len(ac)):
    if tr1 and ac[i] == "[":
        r["["]=i

        tr1=False
        tr2=True
    if tr2 and ac[i]==":" :
        r[":"]=[i]

        tr2=False


flag=True

if tr1 == False and tr2 == False :

    tr3=True
    tr4=False

    for i in range(len(ac)-1,-1,-1):
        if tr3 and ac[i] == "]":
            r["]"]=i
            tr3=False
            tr4=True

        if tr4 and ac[i]==":":
            r[":"].append(i)
            tr4=False


    if tr3 == False and tr4 == False and r[":"][0] != r[":"][1]  and r["["]< r["]"]:
        c=0
        for i in range(r[":"][0]+1,r[":"][1]):
            if ac[i] == "|":
                c+=1

        print(c+4)
        flag=False



if flag:
    print(-1)
