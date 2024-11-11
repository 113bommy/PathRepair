from collections import defaultdict
n,m = tuple(map(int,input().split()))
startswith = defaultdict(list)
endswith = defaultdict(list)
alls = []
for i in range(n):
    s = input()
    alls.append(s)
    startswith[s[0]].append( (s,i) )
    endswith[s[-1]].append( (s,i) )
pairs = [  ]
used = [0]*n
for s in startswith.keys():
    for first, idx1 in startswith[s]:
        for rev, idx2 in endswith[s]:
            if idx1 != idx2 and used[idx1] == 0 and used[idx2] == 0:
                if first == rev[::-1]:
                    used[idx1]=1
                    used[idx2]=1
                    pairs.append( (first,rev) )

single_pals = []
for i in range(n):
    if used[i] == 0 and alls[i]==alls[i][::-1]:
        single_pals.append(alls[i])
                    
if len(pairs)==0 and len(single_pals)==0:
    print(0)
else:
    init, ends =[],[]
    for x,y in pairs:
        init.append(x)
        ends.insert(0,y)
    final = "".join(init+single_pals[0:1]+ends) 
    print( len(final) )
    print(final)