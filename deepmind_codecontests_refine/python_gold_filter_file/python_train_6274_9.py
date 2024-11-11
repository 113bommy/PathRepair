n = int(input())
for i in range(n):
         l=int(input())
         a = list(map(int,input().split()))
         if (len(set(a))==l and max(a)==l):
                  a.reverse()
                  print(*a)