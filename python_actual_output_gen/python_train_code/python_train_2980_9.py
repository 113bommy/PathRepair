n,l,r = map(int,input().split())
t = [1,]
for num in range(1,r):
    t.append(2*t[num-1])
# print(t)
if l == 1:
    minimum = n
else:
    minimum = 1*(n-l+1) + sum(t[1:])
if len(t) == n:
    maximum = sum(t)
else:
    maximum = max(t)*(n-len(t)+1)+sum(t[:r-1])
print(minimum,maximum)