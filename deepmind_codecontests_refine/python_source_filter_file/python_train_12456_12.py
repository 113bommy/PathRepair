def answer():
    n = int(input())
    i=0
    a = [int(x) for x in input().split()]
    visited=[]
    done=0
    while i<len(a):
        if a[i]!=a[a[a[i]-1]-1]:
            print("YES")
            done=1
            break
        i+=1
    if not done: print("NO")
answer()

