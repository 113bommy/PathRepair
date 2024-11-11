N=int(input())
S=""
for i in range(50):
    if N%(-2)==0:
        S=S+"0"
    else:
        S=S+"1"
        N-=1
    N=N//(-2)
print(int(S))