num = list(map(int, input().split()))
k = int(input())
print(max(num)*(2**k-1)+sum(num))