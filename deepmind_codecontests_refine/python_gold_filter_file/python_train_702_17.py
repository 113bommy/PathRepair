n =int(input())
a = list(map(int,input().split()))
s = sum(a)
x = [0]*1000001
for i in a:
    x[i] +=1

q = int(input())
for i in range(q):
    b,c = map(int,input().split())
    s -= b*x[b]
    s += c*x[b]
    x[c] += x[b]
    x[b] = 0
    print(s)