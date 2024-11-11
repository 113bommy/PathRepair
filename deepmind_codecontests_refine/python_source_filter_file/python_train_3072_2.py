n=int(input())
x1,x2 = map(int,input().split())
s=[]
for i in range(n):
    m,b = map(int,input().split())
    s.append([x1*m+b,x2*m+b])

s.sort()

j = 0
for i in range(1,n):
    if s[i-1][1]>s[i][1]: j=1
print(['YES','NO'][j])