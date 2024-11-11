K,A,B = map(int,input().split())
if A+2 >= B:
    print(1+K)
else:
    beatC,m = divmod((K - (A-1)),2)
    print(beatC*(B-A)+(K - 2 * beatC))
