from sys import stdin,stdout
from math import gcd,sqrt,floor,ceil
# Fast I/O
input = stdin.readline
#print = stdout.write

def list_inp(x):return list(map(x,input().split()))
def map_inp(x):return map(x,input().split())

def lcm(a,b): return (a*b)/gcd(a,b)


mat = [[0,0,0,0,0]]

for i in range(3):
    x = list_inp(int)
    x = [0]+x+[0]
    mat.append(x)
mat.append([0,0,0,0,0])
print(mat)

for i in range(1,4):
    for j in range(1,4):
        print((mat[i][j-1]+mat[i-1][j]+mat[i][j]+mat[i+1][j]+mat[i][j+1]+1)%2,end='')
    print()
