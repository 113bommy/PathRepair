d = {}
d["A"]=0
d["B"]=0
d["C"]=0
for i in range(0,3):
    s = input()
    if s[1]==">":
        d[s[0]]+=1
    else: 
        d[s[2]]+=1
d = sorted(d.items(), key = lambda kv:(kv[1], kv[0]),reverse=True)
if d[0][1]==d[1][1] or d[0][1]==d[2][1] or d[2][1]==d[1][1]:
    print("impossible")
else:
    for i in d:
        print(i[0],end = '')