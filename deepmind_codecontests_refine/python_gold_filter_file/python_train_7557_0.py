
def do(cur)->str:
    if len(cur)<len(pt)-1:return"NO"
    i=j=0
    while j<len(cur):
        if pt[i]=="?":
            if cur[j] not in good:return"NO"
        elif pt[i]=="*":
            b=len(cur)-len(pt)+1
            for x in cur[j:j+b]:
                if x in good:return"NO"
            i+=1;j+=b;continue
        else:
            if pt[i]!=cur[j]:return"NO"
        i+=1;j+=1
    return "YES"

good=set(input())
pt=input()
pi=True if "*" not in pt else False
for _ in range(int(input())):
    cur=input()
    if pi and len(cur)!=len(pt):print("NO")
    else:print(do(cur))
