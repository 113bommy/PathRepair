# Why do we fall ? So we can learn to pick ourselves up.



t = int(input())
for _ in range(0,t):
    n = int(input())
    aa = [int(i) for i in input().split()]
    bits = [0]*33
    for x in aa:
        for i in range(0,33):
            if x>>i & 1:
                bits[i] += 1
    ans = "DRAW"
    for i in range(len(bits)-1,-1,-1):
        if bits[i]%2 == 0:
            continue
        if bits[i]%2 and bits[i]%4 == 3 and (n-bits[i])%2 == 0 :
            #player 1 gets even number of bits....effectively ith bit is 0 which is losing...
            #player 2 takes one 1 and then after keep taking 0s so the first player ends with even number of 1s
            ans = "LOSE"
            break
        if bits[i]%2:
            #player 1 gets odd number of bits....effectively ith bit is 1 which is winning...
            ans = "WIN"
            break
    print(ans)



"""

4
5
4 1 5 1 3
4
1 0 1 6
1
0
2
5 4




"""
