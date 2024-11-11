num=int(input())
print(["YES","NO"][all(num%j for j in[4,7,47,744,477])])
