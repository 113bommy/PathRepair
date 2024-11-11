from sys import *
input = stdin.readline

for _ in range(int(input())):
    
    n = int(input())
    
    if(n == 1):
        stdout.write(str(1)+'\n')
    else:
        stdout.write(str(n)+'\n')