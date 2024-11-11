t = int(input())

for i in range(t):
    a, b = map(int, input().split())
    
    if a == b:
        print(0)
    else:
        diff = max(a,b) - min(a,b)
        print((diff//10)+1)