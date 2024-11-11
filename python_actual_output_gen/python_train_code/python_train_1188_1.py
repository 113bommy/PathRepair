n = int(input())
game = list(map(int, input().split()))
game.append(-1)
game.sort()
bitSum = game[1] % 2
rep = False
for i in range(1, n):
    bitSum += game[i + 1] % 2
    if game[i] == game[i + 1]:
        if rep:
            print('cslnb')
            exit(0)
        else:
            if game[i - 1] == game[i] - 1:
                print('cslnb')
                exit(0)
            rep = True
Goal = ((n * (n - 1)) / 2) % 2
if bitSum - Goal == 0:
    print('cslnb')
else:
    print('sjfnb')
