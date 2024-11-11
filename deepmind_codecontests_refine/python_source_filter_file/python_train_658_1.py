n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
d = {}
M  = 0
for i in b:
   for j in a:
      if i%j == 0:
         if i/j >= M:
            M = i/j
            if M not in d:
               d[M]= 0
            d[M] += 1
print(max(d))