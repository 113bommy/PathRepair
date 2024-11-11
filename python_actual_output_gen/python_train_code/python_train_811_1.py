t = int(input())

while t:
    n = int(input())
    l = list(map(int,input().split()))
    even = []
    odd = []
    count = n-1
    for i in range(2*n):
        if l[i]%2==0:
            even.append(i+1)
        else:
            odd.append(i+1)
    
    if len(even)%2!=0:
        even.pop()
    if len(odd)%2!=0:
        odd.pop()
    numbers = even + odd
    
    for i in range(0,len(numbers)-1,2):
        if count!=0:
            print(numbers[i],end='')
            print(numbers[i+1])
        count = count-1
        
    t = t-1
        