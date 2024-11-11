k = int(input())
d={}
t=[]
for i in range(10):
    d[i]=0
for i in range(4):
    arr=input()
    t.append(arr)
for i in range(4):
    for j in range(4):
        if t[i][j]==".":
            continue
        else:
            d[int(t[i][j])]+=1
for i in range(9):
    if d[i]>2*k:
        print("NO")
        break
else:
    print("YES")