n = int(input())
aa = list(map(int,input().split()))
aa.sort()
print(sum(aa[n:2*n]))