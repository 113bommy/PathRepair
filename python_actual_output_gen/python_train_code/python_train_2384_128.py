
local = False
if local:
    file = open("A.txt", "r")

def IN():
    if local:
        return file.readline()
    else:
        return input()

def solve(n,m):
    if m*2==n:
        return "YES"

    return "NO"


t = int(IN())
for i in range(t):   
    n,m = [int(n) for n in IN().split()]
    
    print(solve(n,m))