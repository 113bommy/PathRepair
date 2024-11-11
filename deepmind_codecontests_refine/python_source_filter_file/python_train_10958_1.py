x = int(input())
cases = []
for i in range(x):
    a =  [int(x) for x in input().split()]
    b =  [int(x) for x in input().split()]
    cases.append([a,b])
for i in cases:
        a = i[0]
        b = i[1]
        a0 = a[0]
        a1 = a[1]
        a2 = a[2]
        b0 = b[0]
        b1 = b[1]
        b2 = b[2]
        sum_1 = 0
    
        if(a2>0 and b1>0):
          if(a2>b1):
                sum_1 = sum_1+2*b1
                a2 = a2 - b1
                b1 = 0
                
          else:
                sum_1 = sum_1+2*a2
                b1 = b1 - a2
                a2 = 0
        if(b2>0 and a0>0):
          if(b2>a0):
                b2 = b2 - a0
                b2 = 0
          else:
                a0 = a0 - b2
                b2 = 0
        if(a2>0 and b2>0):
          if(a2>b2):
                a2 = a2 - b2
                b2 = 0
          else:
                b2 = b2 - a2
                a2 = 0
        if(a2>0 and b0>0):
          if(a2>b0):
                a2 = a2 - b0
                b0 = 0
          else:
                b0 = b0 - a2
                a2 = 0
        if(b0>0 and a0>0):
          if(a0>b0):
                a0 = a0 - b0
                b0 = 0
          else:
                b0 = b0 - a0
                a0 = 0
        if(a0>0 and b1>0):
          if(a0>b1):
                a0 = a0 - b1
                b1 = 0
          else:
                b1 = b1 - a0
                a0 = 0
        if(a1>0 and b0>0):
          if(a1>b0):
                a1 = a1 - b0
                b0 = 0
          else:
                b0 = b0 - a1
                a1 = 0
        if(a1>0 and b1>0):
         if(a1>b1):
                a1 = a1 - b1
                b1 = 0
         else:
                b1 = b1 - a1
                a1 = 0
        if(b2>0 and a1>0):
          sum_1 = sum_1 - 2*min(b2,a1)
          b2 = 0
          a1 = 0
          
        print(sum_1)
    
    