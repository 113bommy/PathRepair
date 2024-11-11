x,y=map(int,input().split())
n=list()
t=list()
for i in range(x):
        n.append(input().split())
for i in range(y):
        t.append(input().split())

for i in range(y):
        for j in range(x):
                l=t[i][1][0:len(t[i][1])-1]
                if l == n[j][1]:print(t[i][1],"#"+n[j][0])