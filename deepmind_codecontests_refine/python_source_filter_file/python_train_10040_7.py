
##T = int(input())
T = 1
for _ in range(T):
     n, m = map(int, input().split())
     a = list(map(int, input().split()))
     count = 0
     s = 0
     for num in a:
          if s + num <= m:
               s += num
          else:
               s = num
               count += 1
          count += 1
     print(count)
     
     
     
