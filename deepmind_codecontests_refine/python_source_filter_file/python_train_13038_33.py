t = int(input())
for times in range(t):
    n,m = map(int,input().split())
    area = n*m
    answer = 0
    if(area%2 == 0):
        answer = area/2
        print(answer)
    else:
        answer = (area+1)/2
        print(answer)