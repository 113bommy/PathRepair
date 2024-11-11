n = int(input())

d = []
for k in range(n):
    x = int(input())
    d.append(x)

for a in d:
    c = (a-1)/2
    print(int(8*c*(c+1)*(2*c+1)/6))