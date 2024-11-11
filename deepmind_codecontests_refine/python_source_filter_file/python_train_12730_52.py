from sys import *
for _ in range(int(input())):
    n=int(stdin.readline())
    m=[]
    for i in range(n):
        m.append(str(n*n))
    stdout.write(str(" ".join(m))+"\n")