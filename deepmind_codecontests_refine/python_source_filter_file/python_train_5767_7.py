t,a,b,x,y = map(int, input().split())
word = input().strip()
for i,j in zip(word,range(1,t+1)): 
    if i == 'N' and b<y: 
        b += 1
    elif i == 'S' and b > y: 
        b -= 1
    elif i == 'W' and a>x: 
        a -= 1
    elif i == 'E' and a<x: 
        a += 1
    elif a == x and b == y: 
        print(j)
        exit(0)
else: 
    print(-1)