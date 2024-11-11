n,m="",-1000000
for i in range(int(input())):
    s=input().split()
    z=int(s[1])*100-int(s[2])*50+sum(list(map(int,s[3:])))
    if m<z:n,m=s[0],z
print(n)
    
