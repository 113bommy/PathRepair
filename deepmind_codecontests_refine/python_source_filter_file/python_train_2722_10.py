import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
def linp(): 
    return(list(map(int,input().split())))
n = int(input())
l=[0 for i in range(n)]
for i in range(n):
    l[i] = list(input())
try:
    for i in range(n):
        for j in range(n):
            if  l[i][j]== "." :
                if l[i+1][j]=="." and l[i+2][j]=="." and l[i+1][j+1]=="." and l[i+1][j-1]:
                    l[i+1][j]=l[i+1][j-1]=l[i+1][j+1]=l[i+2][j]="#"
                else:
                    l[1][1][1]
    print("YES")
except:
    print("NO")
    
