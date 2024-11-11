

#c,d,n,m,k=map(int,input().split())
c, d = map(int, input().split())
n, m = map(int, input().split())
k = int(input())

# c и d (1 ≤ c, d ≤ 100)  количество задач в основном и дополнительном раундах 
# n и m (1 ≤ n, m ≤ 100) n победителей
# k (1 ≤ k ≤ 100) — число заранее отобранных победителей

S = 0
if n*m>k :   
    nub = n*m-k
    S = 100000000000
    S0 = S
    i=0
    while S0<=S and i<=int(nub/n+2):
        S = S0  
        S0 = i*c + d*max(0, nub-n*i)
        #print(i,S,S0)
        i += 1

print(S)


