n=int(input())
s=input()
a=[]
for i in range(1,n-1):
    s1=set(s[:i])
    s2=set(s[i:])
    a.append(len(s1&s2))
print(max(a))