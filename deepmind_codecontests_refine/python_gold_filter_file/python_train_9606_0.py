game = int (input())
for f in range(game):
    n = int(input())
    a = list(map(int, input().split()))
    c=0
    count=0
    li=[]
    for value in a:
        c= bin(value)
        li.append(len(c))
    for i in range(1,len(bin(max(a)))+1):
           le=li.count(i)
           if le > 1:
               count+= le*(le-1)//2
    print(count)

