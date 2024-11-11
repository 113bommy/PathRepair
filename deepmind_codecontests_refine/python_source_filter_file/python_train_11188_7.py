q=int(input())
handles=[]
status=True
for i in range(q):
    status=True
    res=input().split(" ")
    if len(handles)==0:
        handles.append(res)
        continue
    for j in handles:
        if j[1]==res[0]:
            j[1]=res[0]
            status=False
            break
    if status:
        handles.append(res)

print(str(len(handles)))
for k in handles:
    print(k[0]+" "+k[1])
