n=int(input())
print(min([sum([int(a) for a in str(i)])+sum([int(b) for b in str(n-i)]) for i in range(int(n/2))]))
