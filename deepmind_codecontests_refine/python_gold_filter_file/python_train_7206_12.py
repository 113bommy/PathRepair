t=int(input())
for i in range(t):
   a,b,x,y=[int(x) for x in input().split()]
   print(max((a-x-1)*b,(b-y-1)*a,(y)*a,(x)*b))
    
    