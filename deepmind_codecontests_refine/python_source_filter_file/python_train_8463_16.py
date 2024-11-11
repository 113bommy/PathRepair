n , m = map(int , input().split())
l=[]
lhs = 0
rhs=0
t=0
for i in range(n):
    temp = str(input())
    if t==1 or temp.count('.')!=len(temp):
        t=1
        l.append(temp)
        if '*' in temp:
            lhs = max(lhs , temp.index('*'))
            rhs = max(rhs , temp.rfind('*'))
t=0
x = l[::-1]
i=0
while t==0:
    if x[i] == m*'.':
        x.remove(x[i])
        i=i-1
    else:
        t=1
    i = i+1
ans = x[::-1]
for i in ans:
    print(i[lhs:rhs+1])