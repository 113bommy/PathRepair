def isAuto(s,x):
    y=""
    if len(x)<len(s):
        return False
    for i in range(len(s)):
        y+=x[i]
    if y==s:
        return True
    else:
        return False
        
def findSLex(L,s):
    if len(L)==0:
        return s
    minimum=L[0]
    for i in range(len(L)):
        if L[i]<L[0]:
            minimum=L[i]
    return minimum    
                
         

s=input()
n=int(input())
i=1
L=[]

while i!=n+1:
    x=input()
    if isAuto(s,x):
        L.append(x)
    i+=1
print(findSLex(L,s))