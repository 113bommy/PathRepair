from sys import stdin,stdout
for _ in range(int(stdin.readline())):
    n,a,b=list(map(int,stdin.readline().split()))
    f=0
    c=1
    if a==1:
        if n%b==1:
            stdout.write('yes\n')
        else:
            stdout.write('no\n')
    else:
     while(c<=n):
        if (n-c)%b==0:
            stdout.write('yes\n')
            f=1
            break
        c=c*a
     if f==0:
          stdout.write('no\n')
