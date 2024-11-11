t = int(input())
i=0
for x in range(t):

    l1 = [int(x) for x in input().split()]
    start = l1[0]
    freq  = l1[1]
    if x==0:
        i = start
    else:
        i+=1
        while i<start or (start-i)%freq:
            i+=1
print(i)
