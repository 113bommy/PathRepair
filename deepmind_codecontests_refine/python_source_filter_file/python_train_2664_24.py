t=int(input())


def proB(n):
    colors='ROYGBIV'
    k=n//7
    ans=''
    
    dic={1:'G',2:'GB'}
    for i in range(k):
        ans+=colors
    shift=n%7
    if(shift in dic):
        ans+=dic.get(shift)
    else:
        ans+=colors[:shift]
    return ans
print(proB(t))