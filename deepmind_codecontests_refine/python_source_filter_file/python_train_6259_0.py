from sys import *

n=int(stdin.readline())
a=[int(z) for z in stdin.readline().split()]
a.sort()
na=[a[0]]
for i in a:
    if i>na[-1]:
        na.append(i)
for i in range(1,len(na)):
    if na[i]<2*na[i-1]:
        stdout.write("yes\n")
        exit(0)
stdout.write("no\n")