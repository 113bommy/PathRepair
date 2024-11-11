n=int(input())
for i in range(n):
    a=int(input())
    if(360%(180-a)):
        print("NO")
    else:
        print("YES")