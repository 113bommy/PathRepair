n1=list(input())
n2=list(input())
l=[]
for i in range(len(n1)-1,-1,-1):
    if n1[i]!=n2[i]:
        l.append("1")
    else:
        l.append("0")
#print(l)
print("".join(l[::-1]))
