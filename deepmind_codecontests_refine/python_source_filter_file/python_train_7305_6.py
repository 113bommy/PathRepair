x=int(input())
for i in range(x):
    n,a,b=map(int,input().split())
    queue = input()
    first = queue.find('1')
    if first == -1:
        print(a * n + b * (n+1))
        continue
    backqueue = queue[::-1]
    last = n-1-backqueue.find('1')
    save = (2*a)//b + 1
    conseczeroes = 0
    total = (n-last+first+1)*(a+b)
    while first <= last:
        if queue[first]==1:
            if conseczeroes >= save:
                total += (conseczeroes+3) * (a+b)
            else:
                total += (conseczeroes+1) * (a+2*b)
            conseczeroes = 0
        else:
            conseczeroes += 1
        first+=1
    print(str(total))
