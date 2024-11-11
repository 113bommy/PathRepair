N,M = map(int,input().split())
list = list(map(int,input().split()))

list.sort()

dif = [b-a for a,b in zip(list,list[1:])]
dif.sort()
print(sum(dif[:M-N]) if N - M > 0 else 0)