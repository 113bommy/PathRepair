n = int(input())
al = list(map(int,input().split()))
al = sorted(al)
print(sum(al[n:2*n]))
