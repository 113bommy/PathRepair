def solution(l1):
    i=1
    targ = l1[0]
    while i<len(l1):
        j=0
        comparator=l1[i]
        case=[]
        while j<len(targ):
            if targ[j]==comparator[j]:
                case.append(targ[j])
            else:
                break
            j+=1
        targ=case
        i+=1
    c_out=""
    for x in targ:
        c_out+=x
    return c_out

def answer():
    n = int(input())
    l1=[]
    while n:
        l1.append(list(input()))
        n-=1
    print(len(solution(l1)))
answer()