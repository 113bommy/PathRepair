def solve(s):
    for i in range(len(s)):
        if(s[i]=="+"):
            break
    a=s[1:i]
    for j in range(i+1,len(s)):
        if(s[j]==")"):
            break
    b=s[i+1:j]
    c=s[j+2:]
    return (int(a)+int(b))//int(c)
m=int(input())
a=[]
for i in range(m):
    s=input()
    a.append(solve(s))
b=list(set(a)) 
dic={}
for i in range(len(b)):
    dic[b[i]]=0
for i in range(len(a)):
    dic[a[i]]+=1
for i in range(len(a)):
    print(dic[a[i]],end=" ")
    