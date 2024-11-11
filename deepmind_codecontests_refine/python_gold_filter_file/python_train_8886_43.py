p=int(input())
s=str(input())
R=G=B=0
for i in range(1,p):
    if(s[i-1]==s[i]):
        if(s[i]=="R"):
            R=R+1
        elif(s[i]=="B"):
            B=B+1
        else:
            G=G+1
        
print(R+G+B)
    