from collections import Counter
t = int(input())
while t:
    s=str(input())
    l=dict(Counter(s))
    c1=0
    c2=0
    for k,v in l.items():
        if l[k]>=2:
            c2+=1
        else:
            c1+=1
    print(c1+(c2//2))
    # j=0
    # for i in range(len(s)):
    #     if(s[i] not in d["red"]):
    #         d["red"].append(s[i])
    #     elif(s[i] not in d["green"]):
    #         d["green"].append(s[i])
    #     else:
    #         d["white"].append(s[i])
    # rlen=len(d["red"])
    # glen=len(d["green"])
    # if(glen==0 and rlen%2==0):
    #     glen=rlen/2
    #     print(glen)
    # elif(glen ==0 and rlen%2==1):
    #     glen=rlen//2
    #     print(glen)
    # elif(len(s)==1):
    #     print(0)
    # else:
    #     while(len(d["red"])!=len(d["green"])):
    #         ele = d["red"].pop()
    #         if ele not in d["green"]:
    #             d["green"].append(ele)
    #         else:
    #             d["red"].insert(0,ele)
    #     print(len(d["red"]))
    t-=1
