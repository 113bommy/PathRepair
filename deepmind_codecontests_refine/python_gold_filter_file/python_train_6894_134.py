
local = False
if local:
    file = open("A.txt", "r")

def IN():
    if local:
        return file.readline()
    else:
        return input()

def solve(n,m):
    if n%m==0:
        return "YES"

    return "NO"


t = int(IN())
for i in range(t):   
    n,m = [int(n) for n in IN().split()]
    
    print(solve(n,m))