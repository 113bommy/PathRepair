x=input()
q=[]
w=[]
e=[]
r=[]
d=dict()
if "!" not in x:
    print(0,0,0,0,sep=" ")
else:
    for i in range(0,len(x),4):
        q.append(x[i])
    for i in range(1,len(x),4):
        w.append(x[i])
    for i in range(2,len(x),4):
        e.append(x[i])
    for i in range(3,len(x),4):
        r.append(x[i])
    d[max(q)]=[q.count("!")]
    d[max(w)]=[w.count("!")]
    d[max(e)]=[e.count("!")]
    d[max(r)]=[r.count("!")]
    print(d["R"],d["B"],d["Y"],d["G"])
