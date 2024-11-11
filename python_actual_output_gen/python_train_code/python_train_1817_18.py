a=int(input())
k=input()
if 'R' in k and 'L' in k:
    t=k.index('L')
    p=k[:t]
    print(p.index('R')+1,len(p))
elif 'R' in k and 'L' not in k:
    p=[]
    for i in k:
        if i=="R":
            p.append(i)
    print(k.index('R')+1,k.index('R')+len(p))
elif 'L'in k and 'R' not in k:
    p = []
    for i in k:
        if i == "L":
            p.append(i)
    print(k.index('L')+len(p),k.index('L')+1)




