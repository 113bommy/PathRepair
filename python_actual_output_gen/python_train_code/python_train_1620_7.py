x,y = map(int,input().split())

p = 0
pr = [300000,200000,100000]

if(x < 3):p += pr[x-1]
if(y < 3):p += pr[y-1]

if(x == y and x == 1):p += 400000

print(p)