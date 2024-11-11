def hst(lst):
   lst.sort()
   h = 0
   for i in range(len(lst)-2):
      h += lst[i+1] - lst[i] - 1
   return h 

T=int(input())
lst = [int(k) for k in input().split(' ') if k]
print(hst(lst))
