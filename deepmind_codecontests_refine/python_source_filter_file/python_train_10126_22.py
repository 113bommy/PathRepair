def ans_f(s):
    char=[0]*26
    for i in s:
        for j in range(26):
            char[j]+=i.count(chr(97+j))
    for i in char:
        if i%2!=0:
            return("NO")
    return("YES")

t= int(input())
ans=[]

for i in range(t):
    n= int(input())
    s=[]
    
    for i in range(n):
        s.append(input())
    ans.append(ans_f(s))

for i in ans:
    print(i)
    
