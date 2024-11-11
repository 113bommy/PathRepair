import sys, os.path, math
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
 
def hcf(a,b):
    if(a%b==0):
        return b
    return hcf(b, a%b) 

###########################################

for t in range(int(input())):
    n = int(input())
    print(n+5,5)