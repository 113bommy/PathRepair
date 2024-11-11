for i in range(int(input())):
    x=int(input())
    count=0
    stair=1
    cell=1 
    while((x-cell)>=0):
        x=x-stair
        count+=1
        stair=(stair*2)+1
        cell=(stair*(stair+1))//2
    print(count)