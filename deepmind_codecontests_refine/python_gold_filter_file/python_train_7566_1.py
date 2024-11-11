n=int(input())
s=input()
l=[i for i in range(1,n+1) if n%i==0]

for j in l:
    a=s[:j]
    b=s[j:]
    a=a[::-1]
    s=a+b
    
print(s)