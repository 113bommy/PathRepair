N,M =[int(i)for i in input().split()]
l=[1]
for i in range(2,int(M**0.5+1)):
    if M%i==0:
        if M/i >= N:
            l.append(i)
        if i >= N:
            l.append(M/i)
print(max(l))