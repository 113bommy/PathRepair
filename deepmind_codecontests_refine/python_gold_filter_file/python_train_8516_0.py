N = int(input())
S = input()
Q = int(input())
K = [int(k) for k in input().split()]

def Counter(S, k):
    Total = 0
    count = [0, 0, 0] #D, M, DMの数
    for i in range(N):
        
        if S[i] == "D": count[0] += 1
        elif S[i] == "M": 
            count[1] += + 1
            count[2] += count[0]
        elif S[i] == "C":
            Total += count[2]
        if i >= k - 1:
            if S[i-k+1] == "D":
                count[0] -= 1
                count[2] -= count[1]
            elif S[i-k+1] == "M":
                count[1] -= 1
    return Total

for i in range(Q):
    print(Counter(S, K[i]))