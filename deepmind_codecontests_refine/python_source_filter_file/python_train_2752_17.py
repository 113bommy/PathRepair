n = int(input())
l = [int(i) for i in input().split()]
c = 0
a = 0
z = 0
if set(l) == {-1}:
    print(n)
if set(l) == {1}:
    print(0)
else:
    for i in range(n):
        if l[i] >= 1:
            c+=l[i]
        else:
            if c < 0:
                z+=1
            else:
                c-=1
    print(z+1)
            
    

  
