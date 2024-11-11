t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split(' ')))
    while len(arr)==n:
        zeroes=0
        ones=0
        for a in arr:
            if a==1:
                ones+=1
            if a==0:
                zeroes+=1
        ans=ones+ones*(zeroes+1)
        print(ans)
        break
    else:
        print('wrong input')
