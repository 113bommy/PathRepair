ls = list(map(int, input().split()))
k =int(input())
print(sum(ls)+max(ls)*(2**k-1))