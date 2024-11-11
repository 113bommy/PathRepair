t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if a<b:
        print(b-a)
    elif a%b==0:
        print(b)
    else:
        print(b-(a%b))   
            
            
            
