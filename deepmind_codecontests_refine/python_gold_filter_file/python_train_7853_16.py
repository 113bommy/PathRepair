import sys
n = int(input())
inp = list(map(int,input().split())) 
mxcount= inp.count(max(inp))
mncount = inp.count(min(inp))
if max(inp) == min(inp):
    print(max(inp) - min(inp),int((mxcount * (mxcount - 1)) / 2)) 
    exit()
print(max(inp) - min(inp),mxcount * mncount)
