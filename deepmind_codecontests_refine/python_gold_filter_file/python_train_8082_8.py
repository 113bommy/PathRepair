
n = int(input())

f = input().split(" ")

a = 0
b = 0
for i in range(0,  n):
    g = int(f[i])
    if( g % 2 == 0): 
        a += 1
    else:
        b += 1
        
if(a > b):
    print(b)
else:
    print(a + (b-a)//3)