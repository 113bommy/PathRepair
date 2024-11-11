N,A,B,C,D=map(int,input().split())
D-=1
l=[]
for i in range(0,N+1):
    l.append(range(i*C-(N-i)*D,i*D-(N-i)*C+1))

for _ in l:
    if B-A in _:
        print("YES")
        break
else:
    print("NO")