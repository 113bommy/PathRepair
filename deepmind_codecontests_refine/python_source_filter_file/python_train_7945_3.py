import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()

l=[]
for _ in range(int(input())):
    
# n=int(input())    
    a,b=get_ints()
    l.append([a,b])
    
c=0
# print(l)
for i in range(0,len(l)):
    f1=0
    f2=0
    f3=0
    f4=0
    for j in range(0,len(l)):
        if(l[i][0]>l[j][0] and l[i][1]==l[j][1]):
            f1+=1
            
        if(l[i][0]<l[j][0] and l[i][0]==l[j][1]):
            f2+=1
            
        if(l[i][1]>l[j][1] and l[i][0]==l[j][0]):
            f3+=1
            
        if(l[i][1]<l[j][1] and l[i][0]==l[j][0]):
            f4+=1
            
    if(f1>0 and f2>0 and f3>0 and f4>0):
        c=c+1
        
print(c)