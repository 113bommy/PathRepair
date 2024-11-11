ordering={'U':0,'L':1,'D':2,'R':3}

from collections import Counter as C

q=int(input())
for _ in range(q):
    s=input()
    n=len(s)
    cnts=C(s)
    if cnts['U']==0 or cnts['D']==0:
        cnts['L']=min(1,cnts['L'])
        cnts['R']=min(1,cnts['R'])
    if cnts['L']==0 or cnts['R']==0:
        cnts['U']=min(1,cnts['D'])
        cnts['D']=min(1,cnts['U'])
    cnts['U']=min(cnts['U'],cnts['D'])
    cnts['D']=cnts['U']
    cnts['L']=min(cnts['L'],cnts['R'])
    cnts['R']=cnts['L']
    ansArr=(['U']*cnts['U'])+(['D']*cnts['D'])+(['L']*cnts['L'])+(['R']*cnts['R'])
    ansArr.sort(key=lambda x:ordering[x])
    print(len(ansArr))
    print(''.join(ansArr))