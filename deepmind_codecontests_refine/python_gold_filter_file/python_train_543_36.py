n=int(input())
for i in range(n):
    a=int(input())
    s=(a-1)//2
    print(((s*(s+1)*(2*s+1))//6)*8)
