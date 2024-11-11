from sys import stdin,stdout
get=stdin.readline;put=stdout.write
n=int(get());a=sorted(list(map(int,get().split())))
print(*a if a[n:]!=a[:n] else [-1])