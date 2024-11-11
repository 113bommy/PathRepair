# cook your dish here
k,p = list(map(int,input().split()))
l = []
t=0
while t<2*k:
    l.append(str(t)+str(t)[::-1])
    t+=1
    
s = list(set([int(i) for i in l]))
s.sort()
print(sum(s[:k+1])%p)