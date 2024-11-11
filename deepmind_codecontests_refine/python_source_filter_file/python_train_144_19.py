a,b=[int(i) for i in input().split()]
m=0
s=[int(i) for i in input().split()]
for i in range(1,len(s)):
    m==max(m,s[i]-s[i-1]-b)
print(m)