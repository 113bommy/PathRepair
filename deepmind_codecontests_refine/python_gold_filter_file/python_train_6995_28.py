n = int(input())
print(["YES","NO"][not any(n%i==0 for i in [4,7,47,447,474,477,744,747,744])])

