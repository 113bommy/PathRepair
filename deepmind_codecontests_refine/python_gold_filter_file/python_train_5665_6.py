import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 


n=iinput()
a=[]
sum,sum1=0,0
for i in range(n):
    a.append(list(map(int,input().split())))
col,col1,col2=0,0,0
for i in range(n):
    if(a[i][0]%2==0):
        col+=1
    sum+=a[i][0]
    if(a[i][1]%2==0):
        col1+=1
    sum1+=a[i][1]
    col2+=((a[i][0]+a[i][1]))%2
if((col==n and col1==n) or(sum%2==0 and sum1%2==0) ):
    print(0)
else:
    if(col2==0):
        print(-1)
    elif(col2%2==0):
        print(1)
    else:
        print(-1)