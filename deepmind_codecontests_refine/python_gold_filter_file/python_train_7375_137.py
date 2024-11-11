N = int(input())
a = sorted(map(int,input().split()))
print(sum(a[N:3*N:2]))