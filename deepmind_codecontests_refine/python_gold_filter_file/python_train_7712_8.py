
n=int(input())
d=list(map(int,input().split()))

s1=[]
sm=0
for dd in d:
    sm+=dd
    s1.append(sm)


s2=[]
sm=0
for dd in d[::-1]:
    sm+=dd
    s2.append(sm)


possibles=sorted(list(set(s1).intersection(s2)))

s1_gen=enumerate(s1)
s2_gen=enumerate(s2)

mx=0
for p in possibles:
    while True:
        index1,ss1=next(s1_gen)
        if ss1==p:
                 break
    
    while True:
        index2,ss2=next(s2_gen)
        if ss2==p:
                 break
    
    if index1+index2<=n-2:
                 mx=p
    else:
                 break
print(mx)

