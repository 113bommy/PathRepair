n = int(input())
s = 1; i  =0
while n - s > 0:
    s = s + i
    i = i +1
    n = n - s
print (i-1 if i-1>0 else "1")
    
