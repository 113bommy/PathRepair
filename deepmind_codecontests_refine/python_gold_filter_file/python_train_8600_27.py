def kalojadu(n):
    li=[1,2,3,5,7,11]
    if n in li:
        return -1
    a= n//4
    if n%4==0: return a
    if n%4==1: return a-1
    if n%4==2: return a
    if n%4==3: return a-1
q= int(input())
for i in range(q):
    print(kalojadu(int(input())))