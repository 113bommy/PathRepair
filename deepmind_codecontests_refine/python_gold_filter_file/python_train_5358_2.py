A=int(input())
B=int(input())
N=A+B+1
print(*[x+1 if x<A else N+A-x for x in range(N)])