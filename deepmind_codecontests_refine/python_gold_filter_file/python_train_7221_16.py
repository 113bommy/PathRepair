n=5
l=[]
for i in range(0,5):
    s=list(map(int,input().strip().split()))
    l.append(s)
#print(l)
#print(l[1][1])
for i in range(len(l)):
    for j in range(len(l[i])):
        if l[i][j]==1:
            print(abs(i-2)+abs(j-2))
    