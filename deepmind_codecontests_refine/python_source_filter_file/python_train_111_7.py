#import sys
#sys.stdin = open("input.in","r")
#sys.stdout = open("test.out","w")
n=int(input())
a=list(map(int,input().split()))
m=sum(a)//n
l=2*m
if l > max(a):
    print(l + 1)
elif l < max(a):
    print(max(a))
else:
    print(l + 1)