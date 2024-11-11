N,*A=map(int, open(0).read().split())
print(sum(sorted(A)[N::2]))