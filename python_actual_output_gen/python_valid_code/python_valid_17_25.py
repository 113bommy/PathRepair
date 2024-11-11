def fu(a):
    b=a//2
    for i  in range(b,0,-1):
        for j in range(a,b+2,-1):
            if j%i==0:
                return i



n=int(input())
for i in range(n):
    a=int(input())
    print(fu(a))