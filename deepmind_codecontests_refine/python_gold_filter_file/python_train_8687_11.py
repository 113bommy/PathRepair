n, m, k=map(int, input().split())
a = [int(input()) for x in range(m+1)]
print(sum([bin(i ^ a[m]).count('1') <= k for i in a])-1)