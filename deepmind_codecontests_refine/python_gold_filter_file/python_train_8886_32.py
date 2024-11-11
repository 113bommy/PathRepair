n=int(input())
s=input()
c=0
for i in range(len(s)-1):
    if(s[i+1]==s[i]):
        c+=1
print(c)