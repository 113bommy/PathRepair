p=input()
p=p.split()
n=int(p[0])
m=int(p[1])
i=1
while i<=n:
    p=''
    if i%2!=0:
        for j in range(m):
            p=p+'#'
        print(p)
    if i%2==0:
        if i%4!=0:
            for j in range(m-1):
                p=p+'.'
            print(p+'#')
        else:
            p=p+'#'
            for j in range(1,m-1):
                p=p+'.'
            print(p)
    i=i+1
