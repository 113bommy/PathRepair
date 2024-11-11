MirorLetters = "AHIMOTUWYV"
X = input()
for i in X:
    if i not in MirorLetters:
        print("NO")
        exit()
print("YES" if X[::-1] == X else "NO")

# UB_CodeForces
# Advice: Falling down is an accident, staying down is a choice
# Location: Here in Bojnurd
# Caption: So Close man!! Take it easy!!!!
# CodeNumber: 655
