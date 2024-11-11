#n = int(input())
a = [int(x) for x in input().split(' ')]
b = [int(x) for x in input().split(' ')]
w = [int(x) for x in input().split(' ')]

bi = 0
wi = 0
count = 0

while wi<len(w) and bi<len(b):
    if w[wi] >= b[bi]:
        bi +=1
        count +=1
    wi +=1

print(count)
