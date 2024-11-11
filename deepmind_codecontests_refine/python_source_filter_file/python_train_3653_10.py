[a,b,x] = list(map(int,input().split()))

out_str = ''

if x%2 == 0:
    if a>b:
        out_str = "01"*(x//2) + "1"*(b-x//2) + "0"*(a-x//2)
    else:
        out_str = "10"*(x//2) + "0"*(b-x//2) + "1"*(a-x//2)
    
else:
    if a>b:
        out_str = "01"*(x//2) + "0"*(a-x//2) + "1"*(b-x//2)
    else:
         out_str = "10"*(x//2) + "1"*(a-x//2) + "0"*(b-x//2)

print(out_str)


