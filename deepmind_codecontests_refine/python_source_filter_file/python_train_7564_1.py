n=int(input())
s=input()
l=[i for i in range(n,0,-1) if n%i==0]

for j in l:
    a=s[:j]
    b=s[j:]
    a=a[::-1]
    s=a+b
    
print(s)