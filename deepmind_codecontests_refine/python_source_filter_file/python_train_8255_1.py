n=int(input())
for i in range(n):
    l=int(input())
    str=input()
    li=[]
    for j in str:
        if j not in li:
            li.append(j)
        else:
            if li[len(li)-1]==j:
                 continue
            else:
                 c=1
                 print("NO")
                 break
    if c!=1:
        print("YES")
             