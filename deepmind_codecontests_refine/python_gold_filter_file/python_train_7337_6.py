def Tekrar(x,liSt):
    d=0
    for i in liSt :
        if i==x:
            d=1
    return d

#---------- Defined / COMPLETE ---------------#

K=int(input())
q=input()
i=0
Tek=[]
Output=[]
while i<len(q):
    Tek.append(q[i])
    Out=''
    while i<len(q)and Tekrar(q[i],Tek)==1 :
        Out+=q[i]
        i+=1
    i+=-1
    if len(Output)==K-1:
        l=i+1
        while l<len(q):
            Out+=q[l]
            l+=1
        Output.append(Out)
        break
    Output.append(Out)
    i+=1

#---------- Finale / OUTPUT ---------------#

if len(Output)==K:
    print("YES")
    for i in Output:
        print(i)
else:
    print("NO")
    
