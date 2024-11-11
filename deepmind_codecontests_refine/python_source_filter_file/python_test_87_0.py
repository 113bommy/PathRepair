n = 0; t = 0; N = [] 
t = int(input())

for w in range(t):
    n = int(input())
    N = list(map(int, input().split()))

    counter = 0
    minus = 0
    old = 0
    for i in range(n):
        if N[i] > old:
            counter += N[i] - old - 1 - minus
            minus = 0
            old = N[i]
        else:
            minus += 1
    
    print(counter)