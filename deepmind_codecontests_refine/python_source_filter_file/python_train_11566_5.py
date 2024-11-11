n = int(input())
l = list(map(int,input().split(' ')))
c = 1
m = []
for i in range(n-1):
       if(l[i] >= l[i+1]):
              c = c+1
              m.append(l[i])
m.append(l[n-1])
print(c)
print(' '.join([str(e) for e in l]))
       