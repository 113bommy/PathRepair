for _ in range(int(input())):
    a,b = map(int, input().split())
    print(max(min(a,b)*2,max(a,b))**(2))