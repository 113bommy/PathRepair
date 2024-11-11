import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
t=int(input())
for tt in range(t):
    n=int(input())
    arr=get_array()
    a1=int(0)
    a2=int(0)
    for v in arr:
        if(v%2==1):
             a1+=1
        else:
             a2+=1
    if(a1>0 &a2>0):
        print("YES")
    elif(a1%2==1):
        print("YES")
    else:
        print("NO")

#n,k = get_ints()
#Arr = get_array()
#Arr.sort()




