n=list(map(int, input().split()))
c=0
n.sort()
if n[0]==n[1]:
    c+=1
if n[1]==n[2]:
    c+=1
if n[2]==n[3]:
    c+=1
print(c)
