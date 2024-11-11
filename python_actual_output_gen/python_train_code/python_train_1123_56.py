a, b, x = map(int, input().split())

print(b//x-min((a-1),0)//x)