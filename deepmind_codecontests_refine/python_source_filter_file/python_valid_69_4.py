t=int(input())
Min=9



for tests in range(t):
    n=input()
    Min=9
    for i in range(61):
        x=str(2**i)
        y=n
        count=0
        Index=0
        for j in range(len(y)):
            if Index<len(x) and y[j]==x[Index]:
                Index+=1
            else:
                count+=1
        count += len(x) - Index
        if count<Min:
            Min=count
    print(Min)