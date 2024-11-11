n,m,k=[int(x) for x in input().split()]
types=[]
for i in range(m+1):
    _=bin(int(input()))[2:]
    _='0'*(n-len(_))+_
    types+=[_] 
result=0
for t in range(m):
    differ=0
    for i in range(n):
        if types[t][i]!=types[-1][i]:
            differ+=1
            if differ==k+1:
                break
    if differ<k+1:
        result+=1
print(result)