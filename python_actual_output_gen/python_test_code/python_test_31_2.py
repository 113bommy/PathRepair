ms=[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
m,d=map(int,input().split())
print(ms[m-1]+d-1//7+1)