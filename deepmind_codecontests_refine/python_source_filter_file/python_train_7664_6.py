d={}
for _ in range(int(input())):
    v=list(map(str,input().split()))
    ss=v[0]
    d[ss]=d.get(ss,set())
    d[ss]|=set(v[2:])
print(len(d))

for ss in d:
    l2=list(d[ss])
    l=[]
    print(l2)
    for i in range(len(l2)):
        for j in range(len(l2)):
            s=str(l2[j])
            if len(l2[j])>len(l2[i]) and s[-len(l2[i]):]==l2[i]:
                l2[i]="a"
            
    # print(l2)        
    l2=list(set(l2))
    if "a" in l2:
        l2.remove("a")
    
    l3=[ss,len(l2)]+l2
    print(*l3)