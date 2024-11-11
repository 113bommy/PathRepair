N = int(input())
As = list(map(lambda x: int(x)//400, input().split()))

As_other = [a for a in As if a<8]
reds = len(As)-len(As_other)

print(len(set(As_other)), len(set(As_other))+reds)