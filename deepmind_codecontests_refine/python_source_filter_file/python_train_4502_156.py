t = int(input())
b=1
x = [int(input()) for x in range(t)]
for a in x:
    if a>b and a/2!=b:
       if a//2==a/2:
           print((a/2)-1)
       else:
           print(int(a//2))
    else:
        print("0")