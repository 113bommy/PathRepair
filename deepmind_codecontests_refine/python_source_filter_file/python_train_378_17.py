n = int(input())
p = input().split(' ')
p = [ int(v) for v in p]
even = [ (i+1)*2 for i in range(n//2)]
odd = [1+(i*2) for i in range(n//2)]

e = 0
o = 0
for i in range(n//2):
    e += abs(even[i]-p[i])
    o += abs(odd[i]-p[i])
    
print(min(e,o))