#n = int(input()) 
n, m = map(int, input().split())
x = - 10 ** 11
for i in range(n):
    k, l = map(int, input().split()) 
    if m > l:
        x = max(x, k - (m - l))
    else:
        x = max(x, k)
print(x)
#s = input()
#c = list(map(int, input().split()))
