import atexit
import io
import sys
import math
from collections import defaultdict,Counter

# _INPUT_LINES = sys.stdin.read().splitlines()
# input = iter(_INPUT_LINES).__next__
# _OUTPUT_BUFFER = io.StringIO()
# sys.stdout = _OUTPUT_BUFFER

# @atexit.register
# def write():
#     sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# m=pow(10,9)+7
n,m=map(int,input().split())
l=[]
for i in range(n):
    s=input()
    l.append(s)
left=''
right=''
p=''
for j in range(len(l)):
    flag=0
    for k in range(j+1,len(l)):
        if l[j]==l[k][::-1]:
            left+=l[j]
            right=l[k]+right
            flag=1
            break
    if flag==0 and len(l[j])>len(p) and l[j]==l[j][::-1]:
        p=l[j]
s1=left+p+right
print(len(s1))
print(s1)