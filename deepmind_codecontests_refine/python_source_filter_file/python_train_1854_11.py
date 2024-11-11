n=str(input())
print("Good" if all([n[j]!=n[j+1] for i in range(3)]) else "Bad")