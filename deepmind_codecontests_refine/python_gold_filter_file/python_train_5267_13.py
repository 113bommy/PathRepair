n, k = map(int,input().split())
names = []
pollU = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
pollL = 'abcdefghijklmnopqrstuvwxyz'
import random
for i in range(105):
    c = pollU[random.randint(1,20)]+pollL[random.randint(1,20)]+pollL[random.randint(1,20)]
    while c not in names:
        c = pollU[random.randint(1,20)]+pollL[random.randint(1,20)]+pollL[random.randint(1,20)]+pollL[random.randint(1,20)]
        if c not in names and c[0].isupper():
            names.append(c)
m = list(input().split())
sol = []
j = k+1
for i in range(len(m)-1):
    if i==0:
        if m[i]=='NO':
            if m[i+1]=='YES':
                sol = [names[0]]
                for tt in range(k):
                    sol.append(names[tt])
            else:
                sol = [names[0]]
                for tt in range(k-1):
                    sol.append(names[tt])
                sol += [sol[-k+1]]
        else:
            if m[i+1]=='YES':
                for tt in range(k):
                    sol.append(names[tt])
                sol += [sol[0]]
            else:
                for tt in range(k):
                    sol.append(names[tt])
                sol += [sol[-k+1]]
    else:
        if m[i+1]=='NO':
            sol += [sol[-k+1]]
        else:
            sol += [names[j]]
            j += 1
if len(m) == 1:
    if m[0]=='NO':
        for tt in range(k):
            sol.append(names[0])
    else:
        for tt in range(k):
            sol.append(names[tt])
            
print(*sol)