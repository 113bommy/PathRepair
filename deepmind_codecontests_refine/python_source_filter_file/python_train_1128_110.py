N=int(input())
A=list(map(int,input().split()))
B=set()
b=0
for a in A:
    if a>=3200:
        b+=1
    else:
        B.add(a//400)
print(len(B),len(B)+b)