n =int(input())
a = [int(input()) for _ in range(n)]
print(int(sum(a)-max(a)/2))