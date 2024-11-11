t = int(input())
for T in range(t):
    n, m = list(map(int, input().split()))
    a = list(map(int,input().split()))
    sum = 0
    for i in a:
        sum+=i; 
    print(max(sum,m));

                
                
                
                
                
                
                