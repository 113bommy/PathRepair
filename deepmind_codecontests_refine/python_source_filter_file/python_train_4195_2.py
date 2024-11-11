from sys import stdin


t = int(input())
for i_t in range(t):
    a, b, c, d = map(int, stdin.readline().split())
    if b*c < a:
        result = -1
    else:
        i_hit = (a + b*d - 1) // (b*d)
        i_hit = min(i_hit, (c-1) // d)
        result = a * (i_hit+1) - b*d * i_hit*(i_hit+1)//2
    print(result)
