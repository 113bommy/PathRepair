K = int(input()) 
S = input()

if len(S) > K:
    a = S[:K]  + '...'

print(a)