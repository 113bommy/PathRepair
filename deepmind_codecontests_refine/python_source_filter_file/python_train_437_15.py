from sys import stdin,stdout
t=int(stdin.readline().strip())
for _ in range(t):
    n=int(stdin.readline().strip())
    a=list(map(int,stdin.readline().strip().split()))
    if n==1:
        stdout.write("0"+"\n")
    else:
        stdout.write(str(len(set(a)))+"\n")
        