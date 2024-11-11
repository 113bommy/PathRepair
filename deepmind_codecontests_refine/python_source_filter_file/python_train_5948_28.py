n=int(input())
s=input()
f=''
a=1
m=1
while a<n:
    a=(m)*(m+1)//2
    f+=s[a-1]
    m+=1
print(f)
