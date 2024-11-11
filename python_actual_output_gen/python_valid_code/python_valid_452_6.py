def get_pairs(l,val):
    from collections import Counter
    d=Counter()
    count=0
    for i,n in enumerate(l):
        if val-n in d:
            count+=d[val-n]
        d[n]+=1
    return count        
            

for _ in range(int(input())):
    N=int(input())
    l=list(map(int,input().split()))
    def func():
        S=sum(l)
        if S%N!=0:
            return 0
        return get_pairs(l,(2*(S))//N)
    print (func())
        
    