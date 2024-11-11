n=list(map(int, input().split()))

#print(n)
p=0
for a in range(max(n[0]+1, n[1]+1)):
    for b in range(max(n[0]+1, n[1]+1)):
        if a*a+b==n[0] and b*b+a==n[1]:
            p+=1
            #print(a,b)
print(p)