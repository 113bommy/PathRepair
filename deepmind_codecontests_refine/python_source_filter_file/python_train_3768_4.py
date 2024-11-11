q = int(input())
B = [0]*q
for i in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    if sum(a)%n==0:
        B[i] = sum(a)/n
    else:
        B[i]=(sum(a)//n)+1
for i in range(q):
    print(B[i])
