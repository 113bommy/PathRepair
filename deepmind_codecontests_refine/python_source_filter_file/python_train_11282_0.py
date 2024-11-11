n=list(input())
p=list(input())
y=0
for x in range(len(p)):
    if p[x]==p[y]:
        y+=1
    else:
        pass
print(y+1)