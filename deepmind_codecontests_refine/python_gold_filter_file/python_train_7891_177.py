X=input()
print(min(abs(int(X[i:i+3])-753) for i in range(len(X)-2)))