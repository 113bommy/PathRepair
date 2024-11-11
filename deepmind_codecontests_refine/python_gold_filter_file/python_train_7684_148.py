a, b = map(int,input().split())
N = b-a
print(N*(N-1)//2 - a)