n=int(input())
z=n
nt=0
m=0
l=[100,50,20,10,5,1]
for i in l:
    nt=nt+n//i
    m=m+(n//i)*i
    if m==z:
        break
    else:
        n=n%i
print(nt)        