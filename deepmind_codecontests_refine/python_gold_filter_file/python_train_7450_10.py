a, b = list(map(int,input().split()))
s = [[2**i,2**(i+1)] for i in range(0,a+1)]

for i in range(0,a+1):
    #print(s[i][0])
    if (b - s[i][0]) % s[i][1] == 0:
        print(i+1)
        break
        
