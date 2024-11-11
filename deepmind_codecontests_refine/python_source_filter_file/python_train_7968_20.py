from sys import stdin,stdout
import math
n=int(stdin.readline().rstrip())
if n<3:
    stdout.write("-1")
else:
    if n%2==0:
        stdout.write(str((n**2)//4-1)+" "+str((n**2)//4-1))
    else:
        stdout.write(str((n**2-1)//2)+" "+str((n**2+1)//2))