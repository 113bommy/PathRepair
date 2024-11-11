a , b = map(int, input().split())
time = 0
while(a>0 and b>0):
    if(a<b):
        temp = a
        a = b
        b = temp
    a -= 2
    b += 1
    if(a>0 and b>0):
        time += 1
print(time)

        
            
