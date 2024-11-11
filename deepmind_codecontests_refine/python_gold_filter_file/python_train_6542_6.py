N,P =map(int, input().split())
A = list(map(int, input().split()))
l0,l1=0,0

for a in A:
    if a%2==0:
        l0 +=1
    else:
        l1 +=1

if P==1 and l1==0:
    print(0)
elif P==0 and l1==0:
    print(2**N)
else:
    print(2**(N-1))