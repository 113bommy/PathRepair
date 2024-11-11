from sys import stdin,stdout
get=stdin.readline;put=stdout.write
n,a=int(get()),sorted(list(map(int,get().split())))
print(a if a[n:]!=a[:n] else -1)