n=int(input())
print(min([sum([int(a) for a in str(i)])+sum([int(b) for b in str(n-i)]) for i in range(1,int(n))]))
