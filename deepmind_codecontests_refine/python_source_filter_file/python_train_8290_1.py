n=input()
a=[]
for i in range(9):
    a.append(input())
s=''
for i in range(7):
    for g in range(len(a)):
        if a[g]==n[10*i:10*(i+1)]:
            s+=str(g)
print(s)