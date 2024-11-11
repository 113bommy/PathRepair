import itertools

N = int(input())
lst = [0]*N
for x,y,z in itertools.product(list(range(1,int(N**0.5))),repeat=3):
    val = x*x + y*y +z*z + x*y + y*z + z*x
    if val <= N-1:
        lst[val-1] += 1
print(*lst,sep="\n")     
