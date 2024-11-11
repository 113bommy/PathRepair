n = int(input())
s = list(map(int,input().split()))
sum = 0
for t in range(n):
    sum += s[t]
if sum == n:
    print(n-1)
else:
    
    output = []
    for i in range(n):
        for j in range(n-i):
            counter = 0
            for k in range(i,i+j+1):
                counter += s[k]
            if counter < (j+1)/2:
                output.append(j+1-2*counter)
            else:
                output.append(int(0))
    maxi = max(output)
    print(sum+maxi)
