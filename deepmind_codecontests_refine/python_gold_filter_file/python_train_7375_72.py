n = int(input())
aa = list(map(int,input().split()))
aa.sort(reverse = True)

print(sum(aa[1:2*n:2]))