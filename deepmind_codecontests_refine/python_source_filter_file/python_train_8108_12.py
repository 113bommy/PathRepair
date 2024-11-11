x = int(input())
score_A = 0
score_B = 0
ans = []
while x:
    for i in range(x):
        y = [int(i) for  i in input().split()]
        if y[0] > y[1]:
            score_A += sum(y)
        elif y[0] < y[1]:
            score_B += sum(y)
        else:
            score_A += y[0]
            score_B += y[1]
    ans.append([score_A,score_B])
    score_A = 0 ; score_B = 0
    x = int(input()
for i in ans:
    print(*i)
