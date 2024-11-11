t = int(input())

for _ in range(0, t):
    a, b, c = map(int, input().split())
    sum = a+b+c;
    
    print(sum//2)