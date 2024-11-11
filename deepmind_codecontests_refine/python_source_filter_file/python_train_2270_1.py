N , K = [int(n) for n in input().split()]
S = input()
print(S[:K]+S[K].lower()+S[K+1:])