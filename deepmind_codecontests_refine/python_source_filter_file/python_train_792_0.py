def transpose(l1, l2):
    # iterate over list l1 to the length of an item
    for i in range(len(l1[0])):
        # print(i)
        row = []
        for item in l1:
            # appending to new list with values and index positions
            # i contains index position and item contains values
            row.append(item[i])
        l2.append(row)
    return l2
n,m = map(int,input().split())
t=n
l=[]
while(t):
    s = input()
    l1 = list(s)
    l.append(l1)
    t-=1
l2 = []
l2 = transpose(l,l2)
l4=[]
for i in range(m):
    la=l[i]
    for j in range(m):
        l3=l2[j]
        if(l3.count(l[i][j])==1 and la.count(l[i][j])==1 not in l4):
            l4.append(l[i][j])
sm=''
for i in range(len(l4)):
    sm = sm+str(l4[i])
print(sm)