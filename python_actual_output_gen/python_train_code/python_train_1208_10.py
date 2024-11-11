#n = int(input())
n, m = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
f = dict()
for i in range(n):
    s, t = input().split()
    f[t] = s 
for i in range(m):
    s, t = input().split()
    print(s + ' '+ t + ' #' + f[t[:-1]] + ';')