x1,y1 = [ord(i)-48 for i in input()]
x2,y2 = [ord(i)-48 for i in input()]
mat = []
while x1!=x2 and y1!=y2:
    s=""
    if x2>x1:
        x1+=1
        s+="R"
    if x2<x1:
        x1-=1
        s+="L"
    if y2>y1:
        y1+=1
        s+="U"
    if y2<y1:
        y1-=1
        s+="D"
    mat.append(s)
    
print(len(mat))
for i in mat:
    print(i)