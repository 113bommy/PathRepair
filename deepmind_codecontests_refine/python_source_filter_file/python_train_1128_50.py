N=int(input())
A=list(map(int,input().split()))
color=set()
free=0
for a in A:
    if a<3200:
        color|={a//400}
    else:
        free+=1
print(str(max(1,len(color)))+' '+str(min(8,len(color)+free)))