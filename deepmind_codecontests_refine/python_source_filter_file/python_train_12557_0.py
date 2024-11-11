# http://codeforces.com/contest/875/problem/A

def getSum(num):
    s = 0
    for char in str(num):
        s += int(char)
    return s + num

n = int(input())
p = []
for i in range(n, (n-9*len(str(n))) -1, -1):
    if i <0: break
    if getSum(i) == n:
        p.append(i)
print(len(p))
for n in p:
    print(n)
