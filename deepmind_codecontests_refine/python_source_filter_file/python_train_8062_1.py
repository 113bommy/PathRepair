n=int(input())
initial=[]
line=input().split()
for i in range(n):
    t=int(line[i])
    initial.append(t)
sort=[]

if n==1:
    fin=int(initial[0])
elif n==2:
    fin=int(initial[0])+int(initial[1])
else:
    fin=0
    sort=sorted(initial)
    for i in range(n-1):
        fin=fin+int(sort[i])*(i+2)
    fin=fin+int(sort[n-1])*n
print(fin)
