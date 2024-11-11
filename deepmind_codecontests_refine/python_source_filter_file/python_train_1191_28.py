#Consistency is the key :)
#code by: amrit2000
from sys import stdin,stdout
import math
import bisect
input=stdin.readline
def print(x='',y='',end='\n'):
    if y=='':
        stdout.write(str(x)+end)
    else:
        stdout.write(str(x)+' '+str(y)+end)

def solve():
    n=int(input())
    l=list(map(int,input().split()))

    st,end=-1,-1
    for i in range(n-1):
        if l[i+1]<l[i]:
            st=i
            break
    for i in range(n-1,0,-1):
        if l[i-1]>l[i]:
            end=i
            break

    if st==-1 and end==-1:
        print('YES')
        print(1,1)
        return

    l[st:end+1]=l[st:end+1][-1::-1]

    for i in range(n-1):
        if l[i+1]<l[i]:
            print('NO')
            return
    print('YES')
    print(st+1,end+1)
        


        
tt=1
#tt=int(input())
for __ in range(tt):
    solve()
