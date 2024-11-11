t = int(input())
for test in range(t):
    n = int(input())
    n = 2*n
    li = list(map(int, input().strip().split()))[:n]
    even=[]
    odd=[]
    for i in range(n):
        if (i % 2 == 0):
            even.append(i+1)
        else:
            odd.append(i+1)
    n = n// 2
    n-=1
    even_pair = len(even)//2
    i=0
    while (n>0 and i<len(even)-1):
        print(even[i],even[i+1])
        i+=2
        n-=1
    i=0    
    while (n>0 and i<len(odd)-1):
        print(odd[i],odd[i+1])
        i+=2
        n-=1        
