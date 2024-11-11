n=int(input())
t=[int(x) for x in input().split()]
one,two,three=0,0,0
for i in range(n):
    if t[i]==1:
        one+=1
    elif t[i]==2:
        two+=1
    elif t[i]==3:
        three+=1
team=min(one,two,three)
print(team)
for j in range(team):
    print(t.index(1),t.index(2),t.index(3))
    t[t.index(1)],t[t.index(2)],t[t.index(3)]=0,0,0