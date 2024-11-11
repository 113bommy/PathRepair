for i in range(int(input())):
    info = list(map(int, input().split()))
    player1= list(map(int, input().split()))
    player2= list(map(int, input().split()))
    if sum(player1)> sum(player2) :
        print("YES")
    else:
        print("NO")