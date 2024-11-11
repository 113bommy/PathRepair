#https://codeforces.com/contest/1152/problem/A
a=input().split(" ")
n=int(a[0])
m=int(a[1])

box=list( map( lambda x : int(x)%2, input().split(" ")))
key=list( map( lambda x : int(x)%2, input().split(" ")))

table=[[0,0],[0,0]]
for i in box:
    if(i==1):
        table[0][1]=table[0][1]+1
    else:
        table[0][0]=table[0][0]+1

for i in key:
    if(i==1):
        table[1][1]=table[1][1]+1
    else:
        table[1][0]=table[1][0]+1
print(min(table[0][0],table[1][1])+min(table[0][1],table[1][0]))