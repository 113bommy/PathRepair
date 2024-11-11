numbers = 26
for _ in range(int(input())):
    n = int(input())
    seq = [int(x)-1 for x in input().split()]  #TODO
    pre = [(n+1)*[0] for i in range(numbers)]
    for j, val in enumerate(seq, 1):
        for i in range(numbers):
            if val == i:
                pre[i][j] = pre[i][j-1] + 1
            else:
                pre[i][j] = pre[i][j-1]
    ans = 1
    for i in range(numbers):  # for x value
        max_val = pre[i][-1] // 2
        for x in range(1, 1+max_val):  # for min x len
            bmin = pre[i].index(x)  # leftmost
            bmax = n-pre[i][::-1].index(pre[i][-1]-x+1)  # right most 
            # print(pre[i],x,bmin, bmax)
            ymax = 0
            if bmax - bmin > 1:       
                for j in range(numbers):  # for y
                    ymax = max(ymax, pre[j][bmax-1] - pre[j][bmin])
            # print('sol', i,x,ymax)
            ans = max(ans, ymax + 2*x)
    # print("ANS ", end='')
    print(ans) 
            