n=int(input())
s=sum(list(map(int, input().split())))+228000*n
print(max(s%n, n-s%n))