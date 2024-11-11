K=int(input())
S=str(input())
if K>=len(S):
    print(S)
else:
    print(S[:K],"...")
