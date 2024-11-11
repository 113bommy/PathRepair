def getbit(n, k):
   return (n >> k) & 1

def sum(n) :
   return n*(n + 1) // 2

def Cal(n):
   if n == 0:
       return 0
   end = 63
   while n < (1 << end):
      end -= 1 
   cnt = 0
   rs = 0
   first = end
   while end >= 0:
     if getbit(n, end) == 1:
        if cnt == 0:
           if end == first:
               rs += max(0, sum(end - 1))
           else:
               rs += 1
     else:
        cnt += 1
        if cnt > 1:
           break
     end -= 1
   if cnt <= 1:
     rs += 1
   return rs

a, b = map(int,  input().split())
print(Cal(b) - Cal(a-1))