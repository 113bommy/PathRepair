s=input()
v="abcdefghijklmnopqrstuvwxyz"
#pnt=25
#print(v[pnt])
ans=""
var=0
for pnt in range(25,-1,-1):
    if v[pnt] in s[var+1:]:
        #print(v[pnt])
        ans+=v[pnt]*s[var+1:].count(v[pnt])
        var=s.rfind(v[pnt])
        #pnt-=1
print(ans)


