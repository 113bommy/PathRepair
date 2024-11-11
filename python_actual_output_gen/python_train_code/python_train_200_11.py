t=int(input())
for _ in range(t):
    s=input()
    z=0
    o=0
    for i in s:
        if i=='1':
            o+=1
        else:
            z+=1
    m=min(z, o)
    if (z%2==0):
        print("NET")
    else:
        print("DA")
