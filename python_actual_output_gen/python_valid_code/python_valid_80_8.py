def myfunc(l1):
    return l1[-1]
def solution(l1,l2,l3):
    n,m,r = l1[0],l1[1],l1[2]
    l2.sort()
    l3.sort()
    l3.reverse()
    i=0
    ans=r
    while r>0 and i<len(l2) and l3[0]-l2[i]>0:
        if r>l2[i]:
            r-=l2[i]
            ans+=l3[0]-l2[i]
        else:
            i+=1
    return ans
    
def answer():
    l1 = [int(x) for x in input().split()]
    l2 = [int(x) for x in input().split()]
    l3 = [int(x) for x in input().split()]
    print(solution(l1,l2,l3))
answer()