n=int(input())
for i in range(n):
    k=input()
    s=list(input())
    print(sum([1 for i,j in zip(s,sorted(s)) if i==j]))