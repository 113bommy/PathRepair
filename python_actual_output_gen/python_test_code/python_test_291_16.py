q=int(input())
for _ in range(q):
    k,n,a,b=map(int,input().split(" "))
    c=k-n*a
    if c>0:
        print(n)
    else:
        turn=(-c+1)/(a-b)
        if turn>=int(turn)+0.5:
            turn+=1
            turn=int(turn)
        else:
            turn=int(turn)
        if n-turn>=0:
            print(n-turn)
        else:
            print(-1)
        