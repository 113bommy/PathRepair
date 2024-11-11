n = int(input())
a = map(int, input().split())
c = [0]*9

for i in a:
    col = i//400
    if 4800<= i:
        c[8] += 1
    else:
        c[col] = 1
print(max(1,sum(c[:8])),sum(c))