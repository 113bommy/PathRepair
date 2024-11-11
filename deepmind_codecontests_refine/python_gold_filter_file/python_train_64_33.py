Middle = 10 ** 6 // 2
input()
X = list(map(int, input().split()))
After, Before = list(filter(lambda x: x > Middle, X)), list(filter(lambda x: x <= Middle, X))
Before.append(1)
After.append(10 ** 6)
print(min(max(X) - 1, 10 ** 6 - min(X), max(max(Before) - 1, (10 ** 6) - min(After))))

# UB_CodeForces
# Advice: Falling down is an accident, staying down is a choice
# Location: Here in Bojnurd
# Caption: Being followed by my friend ESSI
# CodeNumber: 618
