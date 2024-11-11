#import sys
#import math
#sys.stdout=open("C:/Users/pipal/OneDrive/Desktop/VS code/python/output.txt","w")
#sys.stdin=open("C:/Users/pipal/OneDrive/Desktop/VS code/python/input.txt","r")
#t=int(input())
#for i in range(t): 
n,m=map(int,input().split())
l=[]
c=0
for i in range(105):
    l.append(0)
for i in range(n):
    le,r=map(int,input().split())
    for j in range(le,r+1):
        l[j]=1

for i in range(1,m):
    if l[i]==0:
        c+=1

print(c)
for i in range(1,m):
    if l[i]==0:print(i,end=" ")
print()









    