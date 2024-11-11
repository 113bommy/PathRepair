n = int(input())
l = input()
N = 0

for x in l:
    if x == '8':
        N += 1
        
n //= 10
n = min(N, n)

print (n)
