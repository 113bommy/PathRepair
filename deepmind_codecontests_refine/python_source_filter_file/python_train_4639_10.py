x, y = map(int, input().split()) 
n = int(input())
#n, m = map(int, input().split()) 
#s = input()
#c = list(map(int, input().split()))
t = 10 ** 7
for i in range(n):
    k, m, l = map(int, input().split()) 
    t = min(t,(((x + k) ** 2 + (y + m) ** 2) ** 0.5) / l)
print(t)