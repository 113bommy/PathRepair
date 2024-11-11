t=int(input())
s=input()
s=list(s)

c=k=0
for i in range(0,len(s)-1):
    if(s[i]=="S" and s[i+1]=="F"):
        c=c+1
    elif(s[i]=="F" and s[i+1]=="S"):
        k=k+1
if(c>k):
    print("YES")
else:
    print("NO")