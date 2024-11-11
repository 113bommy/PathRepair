n=int(input())
a=n*[0]
s=input()
a=s.split()
for i in range(n):
    a[i]=int(a[i])
for i in range(1,51):
    div=51-i
    boolean=1
    for i in range(n):
        if a[i]%div!=0:
            boolean=0
    if boolean==1:
        print(n*div)
        break