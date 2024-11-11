#JMD
#Nagendra Jha-4096

 
import sys
import math

#import fractions
#import numpy
 
###File Operations###
fileoperation=0
if(fileoperation):
    orig_stdout = sys.stdout
    orig_stdin = sys.stdin
    inputfile = open('W:/Competitive Programming/input.txt', 'r')
    outputfile = open('W:/Competitive Programming/output.txt', 'w')
    sys.stdin = inputfile
    sys.stdout = outputfile

###Defines...###
mod=1000000007
 
###FUF's...###
def nospace(l):
    ans=''.join(str(i) for i in l)
    return ans
 
 
 
##### Main ####
t=int(input())
for tt in range(t):
    #n=int(input())
    n,x= map(int, sys.stdin.readline().split(' '))
    a=list(map(int,sys.stdin.readline().split(' ')))
    o=0
    for v in a:
        if v%2==1:
            o+=1
    e=n-o

    f=0

    for p in range(1,o+1,2):
        r=x-p
        if r<=e:
            f=1
            break
    if f==1:
        print("Yes")
    else:
        print("No")
    
    
#####File Operations#####
if(fileoperation):
    sys.stdout = orig_stdout
    sys.stdin = orig_stdin
    inputfile.close()
    outputfile.close()