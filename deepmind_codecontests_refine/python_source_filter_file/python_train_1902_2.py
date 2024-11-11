import collections
def cakes(A):
    n=len(A)
    z=collections.Counter(A)
    res=[]
    for i in z.keys():
        res.append([z[i],i])
    res.sort(reverse=True)
    chamber=res[0][0]-1
    vacant=chamber
    count=0
    for i in range(1,len(res)):
        if res[i][0]>=res[0][0]:
            res[i][0]=res[0][0]-1
            count+=1
            vacant=chamber
        else:
            freq=res[i][0]
            if freq==chamber:
                count+=1
                vacant=chamber
            else:
                vacant=vacant-freq
                if vacant<=0:
                    count+=1
                    vacant=chamber
    return count
t=int(input())
for i in range(t):
    n=int(input())
    A=[int(i) for i in input().split()][:n]
    print(cakes(A))