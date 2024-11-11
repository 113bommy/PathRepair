T = int(input())

for t in range(T):
    
    n = int(input())
    
    if n <= 2:
        print(0)
        continue
    
    if n%2 == 0:
        print(n/2)
    else:
        print(int(n/2))