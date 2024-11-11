n=int(input())
rem=[int(x) for x in input().split()]
cap=[int(x) for x in input().split()]

rems=0
cap2=[0,0]
for i in range(n):
    rems+=rem[i]
    if cap[i]>cap2[0]:
        cap2[1]=cap2[0]
        cap2[0]=cap[i]
    elif cap[i]>cap2[1]:
        cap2[1]=cap[i]
caps=cap[0]+cap[1]
if caps>=rems:
    print("YES")
else:
    print("NO")