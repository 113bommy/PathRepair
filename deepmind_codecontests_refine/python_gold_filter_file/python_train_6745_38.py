S=input()
print(sum(i!=j for i,j in zip(S,S[::-1]))//2)