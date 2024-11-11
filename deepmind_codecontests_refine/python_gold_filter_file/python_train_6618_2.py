myname=input();n=int(input());priority={}
def func(action):
    if action[1]=="posted":k=15
    else: k=10
    if action[1]=="posted" or action[1]=="commented":
        name2,s=[x for x in action[3].split("'")]
        if action[0]==myname or name2==myname:
            if action[0] in priority:
                priority[action[0]]+=k
            else:
                priority[action[0]]=k
            if name2 in priority:
                priority[name2]+=k
            else:
                priority[name2]=k
        else:
            if action[0] not in priority:
                priority[action[0]]=0
            if name2 not in priority:
                priority[name2]=0

    else:
        name2,s=[x for x in action[2].split("'")]
        if action[0]==myname or name2==myname:
            if action[0] in priority:
                priority[action[0]]+=5
            else:
                priority[action[0]]=5
            if name2 in priority:
                priority[name2]+=5
            else:
                priority[name2]=5
        else:
            if action[0] not in priority:
                priority[action[0]]=0
            if name2 not in priority:
                priority[name2]=0

while n>0:
    n-=1
    action=[x for x in input().split(" ")]
    func(action)
try:
    priority.pop(myname)
except KeyError as e:
    pass
k=[];v=[]
for key,val in priority.items():
    k.append(key)
    v.append(val)
n=len(v)
for i in range(n-1):
    swapped=False
    for j in range(n-1-i):
        if v[j]<v[j+1]:
            v[j],v[j+1]=v[j+1],v[j]
            k[j],k[j+1]=k[j+1],k[j]
            swapped=True
        elif v[j]==v[j+1]:
            if k[j]>k[j+1]:
                v[j],v[j+1]=v[j+1],v[j]
                k[j],k[j+1]=k[j+1],k[j]
                swapped=True
    if not swapped:
        break
for item in k:
    print(item)


