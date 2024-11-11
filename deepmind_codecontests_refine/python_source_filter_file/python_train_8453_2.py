from sys import stdin, stdout
for _ in range(int(input())):
    a,b=map(int,input().split())
    mp=[]
    one=False
    every=True
    for _ in range(a):
        mp.append([])
        for x in stdin.readline().strip():
            
            if x=='A':
                mp[-1].append(1)
                one=True
            else:
                mp[-1].append(0)
                every=False                
    for x in mp:
        print(x)
    if every==True:
        print(0)
        continue
    if one==False:
        print('MORTAL')
        continue

    line=[]
    for i in (0,-1):
        line.append(mp[i])
        line.append([])
        for j in range(a):
            line[-1].append(mp[j][i])
    t=[]
    s=[]
    for x in line:
        t.append(all(x))
        s.append(any(x))
    if any(t):
        print(1)
        continue
    u=[]
    for i in (0,-1):
        for j in (0,-1):
            u.append(mp[i][j])
    for x in mp:
        u.append(all(x))
    for i in range(b):
        u.append(all([mp[j][i] for j in range(a)]))
    if any(u):
        print(2)
    elif any(s):
        print(3)
    else:
        print(4)