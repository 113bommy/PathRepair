a = list(map(int, input().split()))
n = int(input())
print(sum(a)+max(a)*2**n-max(a))