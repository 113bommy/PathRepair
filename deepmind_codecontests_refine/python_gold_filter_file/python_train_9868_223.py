N,R=map(int,input().split())
if N <= 10:
    R += 100*(10 - N)
print(R)