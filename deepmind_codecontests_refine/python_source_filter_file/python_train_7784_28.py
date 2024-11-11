N,M=map(int, input().split())
d=set()
a,b=1,N
for _ in range(M):
    print(a,b)
    d.add(b-a)
    d.add(N-b+a)
    a+=1
    b-=1
    while b-a in d or N-b+a in d or b-a == N-b+a: b-=1
print(d)